#include "includes/events/ModeChangeEvent.h"

ModeChangeEvent::ModeChangeEvent(Modes old, Modes now):
    EventBase(),
    lastMode(old),
    nextMode(now)
{}

PreModeChangeEvent::PreModeChangeEvent(Modes old, Modes now):
    ModeChangeEvent(old,now)
{}

PostModeChangeEvent::PostModeChangeEvent(Modes old, Modes now):
    ModeChangeEvent(old,now)
{}

