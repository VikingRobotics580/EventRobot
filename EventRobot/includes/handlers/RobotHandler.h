#ifndef _ROBOT_HANDLER_H_
#define _ROBOT_HANDLER_H_

#include "WPILib.h"
#include "HAL/HAL.hpp"

#include "EventHandler.h"
#include "../events/TickEvent.h"
#include "../events/ModeChangeEvent.h"
#include "../EventSubscribe.h"
#include "../EventRobot.h"
#include "../event_robot_types.h"

class RobotHandler: public EventHandler<RobotHandler> {
    public:
        RobotHandler();
        ~RobotHandler();

        EVENT_SUBSCRIBE(TickEvent,LOW,onTick)
        int onTick(TickEvent* e){
            EventRobot* caller = e->caller;

            Modes mode = caller->getMode();
            caller->checkForModeChange();
            Modes newMode = caller->getMode();

            if(mode != newMode){
                EventRobot::EVENT_BUS->post(new PreModeChangeEvent(mode,newMode));
            }

            if(newMode == Modes::DISABLED){
                HALNetworkCommunicationObserveUserProgramDisabled();
            }else if(newMode == Modes::AUTONOMOUS){
                HALNetworkCommunicationObserveUserProgramAutonomous();
            }else if(newMode == Modes::TEST){
                HALNetworkCommunicationObserveUserProgramTest();
            }else if(newMode == Modes::NONE){
                // Skip the rest if the current mode is invalid
                return 1;
            }else{
                HALNetworkCommunicationObserveUserProgramTeleop();
            }
        }

        // PreModeChange -> ModeChange -> PostModeChange
        // We catch each one and make sure they are called one after the other
        // Make sure to check the lifecycle so that we only call it after it has made the rounds
        EVENT_SUBSCRIBE(PreModeChangeEvent,LOW,onPreModeChange)
        void onPreModeChange(PreModeChangeEvent* event){
            if(event->lifecycle >= 1){
                event->canceled = true;
                EventRobot::EVENT_BUS->post(new ModeChangeEvent(event->lastMode,event->nextMode));
            }
        }

        EVENT_SUBSCRIBE(ModeChangeEvent,LOW,onModeChange)
        void onModeChange(ModeChangeEvent* event){
            if(event->lifecycle >= 1){
                event->canceled = true;
                EventRobot::EVENT_BUS->post(new PostModeChangeEvent(event->lastMode,event->nextMode));
            }
        }
};

#endif

