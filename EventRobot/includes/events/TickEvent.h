#ifndef _TICK_EVENT_H_
#define _TICK_EVENT_H_

#include "EventBase.h"
#include "../EventRobot.h"

class TickEvent: public EventBase<TickEvent> {
    public:
        TickEvent(EventRobot*);
        // As long an int as we can make
        static unsigned long long int num_ticks;

        const static int ID = 1;

        EventRobot* caller;
};

#endif

