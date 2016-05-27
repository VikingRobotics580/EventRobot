#include <iostream>

#include "WPILib.h"
#include "HAL/HAL.hpp"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

#include "includes/events/EventBase.h"
#include "includes/events/TickEvent.h"
#include "includes/events/RobotInitializationEvent.h"
#include "includes/events/EventHandlerErrorEvent.h"
#include "includes/handlers/RobotHandler.h"
#include "includes/EventRobot.h"

EventBus* const EventRobot::EVENT_BUS = new EventBus();

EventRobot::EventRobot():
    RobotBase(),
    m_handlers(),
    m_mode()
{
    registerHandler(new RobotHandler());
}

EventRobot::~EventRobot(){
    for(size_t i=0; i<m_handlers.size(); i++){
        delete m_handlers.at(i);
    }

    delete EVENT_BUS;
}

void EventRobot::registerHandler(IHandler* handler){
    // TODO: Make each handler get inserted at the start of the list, so that RobotHandler is called last
    m_handlers.push_back(handler);
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
        for(auto& event : EVENT_BUS->getEvents()){
            for(auto& handler : m_handlers){
                handler->__handle_event_HIGHEST(event->getActualType());
                handler->__handle_event_HIGH(event->getActualType());
                handler->__handle_event_NORMAL(event->getActualType());
                handler->__handle_event_LOW(event->getActualType());
                handler->__handle_event_LOWEST(event->getActualType());
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

