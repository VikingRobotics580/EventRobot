#include <iostream>

#include "WPILib.h"
#include "HAL/HAL.hpp"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

#include "includes/events/EventBase.h"
#include "includes/events/TickEvent.h"
#include "includes/events/RobotInitializationEvent.h"
#include "includes/events/EventHandlerErrorEvent.h"
#include "includes/event_robot_types.h"
#include "includes/EventRobot.h"

EventBus* const EventRobot::EVENT_BUS = new EventBus();

EventRobot::EventRobot():
    RobotBase(),
    m_handlers(),
    m_mode()
{
    registerHandler(new RobotHandler(),HandlerPriority::LOWEST);
}

EventRobot::~EventRobot(){
    for(handlermap::iterator it=m_handlers.begin(); it != m_handlers.end(); ++it){
        std::vector<EventHandler*> list = it->second;
        for(size_t i=0; i < list.size(); i++){
            delete list.at(i);
        }
    }

    delete EVENT_BUS;
}

/*
 * registerHandler
 * Accepts an EventHandler* and an optional HandlerPriority
 *   If priority is not specified, then HandlerPriority::NORMAL is assumed
 * Returns nothing
 * Registers a handler with this EventRobot instance. The priority parameter specifies which order to execute each handler.
 *  HIGHEST priority executes first, while LOWEST priority executes last
 */
void EventRobot::registerHandler(EventHandler* handler,HandlerPriority priority=HandlerPriority::NORMAL){
    if(m_handlers.find(priority) != m_handlers.end())
        m_handlers[priority] = std::vector<EventHandler*>();
    m_handlers.at(priority).push_back(handler);
}

void EventRobot::StartCompetition(){
    HALReport(HALUsageReporting::kResourceType_Framework,HALUsageReporting::kFramework_Iterative);
    LiveWindow *lw = LiveWindow::GetInstance();
    // TODO: Find out why this throws an undefined reference linker error
    //SmartDashboard::init();
    NetworkTable::GetTable("LiveWindow")->GetSubTable("~STATUS~")->PutBoolean("LW Enabled",false);
    EVENT_BUS->post(new RobotInitializationEvent());

    HALNetworkCommunicationObserveUserProgramStarting();
    lw->SetEnabled(false);

    while(true){
        EVENT_BUS->post(new TickEvent(this));
        for(handlermap::iterator it=m_handlers.begin(); it != m_handlers.end(); ++it){
            for(auto& handler : it->second){
                if(handler->Update(EVENT_BUS->getEvents())){
                    EVENT_BUS->post(new EventHandlerErrorEvent());
                }
            }
        }
        EVENT_BUS->Update();
        m_ds.WaitForData();
    }
}

void EventRobot::checkForModeChange(){
    if(IsDisabled()){
        m_mode = Modes::DISABLED;
    }else{
        if(IsAutonomous())
            m_mode = Modes::AUTONOMOUS;
        else if(IsOperatorControl())
            m_mode = Modes::OPERATOR;
        else if(IsTest())
            m_mode = Modes::TEST;
        else
            m_mode = Modes::NONE;
    }
}

