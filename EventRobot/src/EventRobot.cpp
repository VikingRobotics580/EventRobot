#include "WPILib.h"
#include "includes/events/EventBase.h"
#include "includes/events/TickEvent.h"
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

void EventRobot::registerHandler(EventHandler* handler){
    // TODO: Make each handler get inserted at the start of the list, so that RobotHandler is called last
    m_handlers.push_back(handler);
}

void EventRobot::StartCompetition(){
    EVENT_BUS->post(new TickEvent(this));
    for(auto& handler : m_handlers)
        handler->Update(EVENT_BUS->getEvents());
    EVENT_BUS->Update();
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

