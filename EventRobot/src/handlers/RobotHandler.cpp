#include "RobotHandler.h"
#include "events/TickEvent.h"
#include "events/PreModeChangeEvent.h"
#include "events/ModeChangeEvent.h"
#include "events/PostModeChangeEvent.h"
#include "EventRobot.h"

RobotHandler::RobotHandler():
    EventHandler()
{}

RobotHandler::~RobotHandler(){ }

int RobotHandler::Update(event_list events){
    for(auto& event : events){
        if(event.eid == TickEvent::ID){
            EventRobot* caller = ((TickEvent*)event)->caller;

            Modes mode = caller->getMode();
            caller->checkForModeChange();
            Modes newMode = caller->getMode();

            // A mode change has occurred!
            if(mode != newMode){
                EventRobot::EVENT_BUS->post(new PreModeChangeEvent(mode,newMode));
            }

        // PreModeChange -> ModeChange -> PostModeChange
        // We catch each one and make sure they are called one after the other
        // Make sure to check the lifecycle so that we only call it after it has made the rounds
        }else if(event.eid == PreModeChangeEvent::ID && event.lifecycle >= 1){
            event->setCanceled(true);
            EventRobot::EVENT_BUS->post(new ModeChangeEvent(mode,newMode));
        }else if(event.eid == ModeChangeEvent::ID && event.lifecycle >= 1){
            event->setCanceled(true);
            EventRobot::EVENT_BUS->post(new PostModeChangeEvent(mode,newMode));
        }
    }
    return 0;
}

