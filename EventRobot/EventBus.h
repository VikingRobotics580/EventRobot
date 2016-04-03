#ifndef _EVENT_BUS_H_
#define _EVENT_BUS_H_

#include <vector>
#include "events/EventBase.h"
#include "event_robot_types.h"

class EventBus {
    public:
        EventBus();
        ~EventBus();

        void post(EventBase*);
        void Update();

        inline event_list& getEvents(){ return m_event_list; };

        const static int MAX_LIFECYCLE_TIME = 10;
    private:
        event_list m_event_list;
};

#endif

