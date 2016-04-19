#include "includes/events/TickEvent.h"

unsigned long long int TickEvent::num_ticks = 0;

TickEvent::TickEvent(EventRobot* caller):
    EventBase()
{
    this->caller = caller;
}

