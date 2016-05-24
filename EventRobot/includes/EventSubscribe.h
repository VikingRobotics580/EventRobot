#ifndef _EVENT_SUBSCRIBE_H_
#define _EVENT_SUBSCRIBE_H_

#include "event_robot_types.h"

// A preprocessor macro which defines a special method to be called by EventRobot when a handler is doing its job
#define EVENT_SUBSCRIBE(EVENTTYPE,PRIORITY,func) \
    public: \
        template<> \
        void __handle_event<EVENTTYPE>(EVENTTYPE e){ \
            /* Ensure that the function is registered*/ \
            if(this->__func_idx__ == NULL){ \
                std::function<void(EVENTTYPE)>* f = func; \
                /*this->_functions.at(PRIORITY).push_back(f); */\
            } \
            func(e); \

#define EventSubscribe(e,f) EVENT_SUBSCRIBE(e,Priorities::NORMAL,f)

#endif

