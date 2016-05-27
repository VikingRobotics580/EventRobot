#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "../events/EventBase.h"
#include "../event_robot_types.h"

// This is here so that we can fix that whole "missing copy constructor" issue
// Well, it isn't really that, but the issue was a crash with the message "double free or corruption (fasttop)"
// And this could only be fixed by using a copy constructor
// Unfortunately, because EventHandler is abstract, it cannot have a copy constructor because reasons
struct IHandler{
    IHandler(){};
    IHandler(const IHandler&){};
    IHandler& operator=(const IHandler&){
        return *this;
    };
};

template<typename T>
class EventHandler: public IHandler{
    public:
        EventHandler();
        virtual ~EventHandler();
        virtual int Update(event_list&)=0;

        // Get the real type of the object
        inline T* getActualType(){
            return static_cast<T*>(this);
        };

        virtual void __handle_event_HIGHEST(IEventBase*){};
        virtual void __handle_event_HIGH(IEventBase*){};
        virtual void __handle_event_NORMAL(IEventBase*){};
        virtual void __handle_event_LOW(IEventBase*){};
        virtual void __handle_event_LOWEST(IEventBase*){};
};

#endif

