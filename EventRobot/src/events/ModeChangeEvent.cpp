#include "includes/events/ModeChangeEvent.h"

ModeChangeEvent::ModeChangeEvent(Modes old, Modes now):
    EventBase(),
    lastMode(old),
    nextMode(now)
{
    eid = ID;
}

PreModeChangeEvent::PreModeChangeEvent(Modes old, Modes now):
    ModeChangeEvent(old,now)
{
    eid = ID;
}

PostModeChangeEvent::PostModeChangeEvent(Modes old, Modes now):
    ModeChangeEvent(old,now)
{
    eid = ID;
}

