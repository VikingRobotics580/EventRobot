#ifndef _ROBOT_HANDLER_H_
#define _ROBOT_HANDLER_H_

#include "handlers/EventHandler.h"
#include "EventRobot.h"

class RobotHandler: public EventHandler {
    public:
        RobotHandler();
        ~RobotHandler();
        int Update(event_list& events);
};

#endif

