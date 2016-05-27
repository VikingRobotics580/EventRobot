#ifndef _ROBOT_INITIALIZATION_EVENT_H_
#define _ROBOT_INITIALIZATION_EVENT_H_

#include "EventBase.h"

struct RobotInitializationEvent: public EventBase<RobotInitializationEvent>{
    RobotInitializationEvent(){ eid = ID; };
    const static int ID = 5;
};

#endif

