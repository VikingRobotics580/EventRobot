#include "includes/events/TickEvent.h"

TickEvent::num_ticks = 0;

TickEvent::TickEvent(EventRobot* caller):
    EventBase()
{
    this->caller = caller;
}

