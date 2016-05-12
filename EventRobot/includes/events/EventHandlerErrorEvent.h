#ifndef _EVENT_HANDLER_ERROR_EVENT_H_
#define _EVENT_HANDLER_ERROR_EVENT_H_

struct EventHandlerErrorEvent: public EventBase{
    EventHandlerErrorEvent(){ eid = ID; };
    const static int ID = 6;
};

#endif

