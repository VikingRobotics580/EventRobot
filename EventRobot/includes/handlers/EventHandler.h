#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

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

class EventHandler: public IHandler{
    public:
        EventHandler();
        virtual ~EventHandler();
        virtual int Update(event_list&)=0;

        // A method to be overriden later by subclasses
        template<typename T>
        void __handle_event(){};
        /*
    private:
        std::map< Priorities, std::vector<void(EventBase)> > _functions;
        */
};

#endif

