#ifndef _EVENT_BASE_H_
#define _EVENT_BASE_H_

#include <typeinfo>
//#include "includes/EventRobot.h"

struct IEventBase{
    // Here rather than in EventBase to satisfy the compiler
    int priority;
};

template<typename T>
struct EventBase: public IEventBase {
        int eid;
        int lifecycle;
        bool canceled;

        inline T* getActualType(){
            return static_cast<T*>(this);
        }

        static int getID(){
            static const int id = reinterpret_cast<int>(typeid(T).name());
            return id;
        }
};

#endif

