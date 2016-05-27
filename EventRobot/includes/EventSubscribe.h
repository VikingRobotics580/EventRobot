#ifndef _EVENT_SUBSCRIBE_H_
#define _EVENT_SUBSCRIBE_H_

#include "event_robot_types.h"

// A preprocessor macro which defines a special method to be called by EventRobot when a handler is doing its job
#define EVENT_SUBSCRIBE(EVENTTYPE,PRIORITY,FUNCTION) \
        void __handle_event_##PRIORITY (EVENTTYPE* e){ \
            FUNCTION(e); \
        }

#endif

