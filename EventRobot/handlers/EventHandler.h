#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "../event_robot_types.h"

class EventHandler{
    public:
        EventHandler();
        virtual ~EventHandler();
        virtual int Update(event_list&)=0;
};

#endif

