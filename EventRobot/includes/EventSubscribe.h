#ifndef _EVENT_SUBSCRIBE_H_
#define _EVENT_SUBSCRIBE_H_

#include "event_robot_types.h"
#include "events/EventBase.h"

// A preprocessor macro which defines a special method to be called by EventRobot when a handler is doing its job
#define EVENT_SUBSCRIBE(EVENTTYPE,PRIORITY,FUNCTION) \
        void __handle_event_##PRIORITY (EVENTTYPE* e){ \
            FUNCTION(e); \
        }

#define SUBSCRIBE_START \
    void subscribe(IEventBase* _event){
#define SUBSCRIBE_END \
        return; \
    }
#define SUBSCRIBE(TYPE,PRIORITY,FUNC) \
    if(reinterpret_cast<TYPE*>(_event) && _event->priority == PRIORITY){ \
        FUNC(reinterpret_cast<TYPE*>(_event)); \
    }else 

#endif

