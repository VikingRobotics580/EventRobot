
#include "EventRobot.h"
#include "handlers/RobotHandler.h"

EventRobot::EVENT_BUS = new EventBus();
EventRobot::instance = NULL;

EventRobot::EventRobot():
    BaseRobot(),
    handlers(),
    m_mode()
{
    registerHandler(new RobotHandler());
}

EventRobot::~EventRobot(){
    for(int i=0; i<handlers.size(); i++){
        delete handlers.at(i);
    }

    delete EVENT_BUS;
}

void EventRobot::registerHandler(EventHandler* handler){
    // TODO: Make each handler get inserted at the start of the list, so that RobotHandler is called last
    handlers.push_back(handler);
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

EventRobot* EventRobot::getInstance(){
    if(instance == NULL)
        instnace = new EventRobot();
    return instance;
}

