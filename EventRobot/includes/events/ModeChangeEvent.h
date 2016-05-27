#ifndef _MODE_CHANGE_EVENT_H_
#define _MODE_CHANGE_EVENT_H_
#include "EventBase.h"
#include "../EventRobot.h"

class ModeChangeEvent: public EventBase<ModeChangeEvent>{
    public:
        ModeChangeEvent(Modes, Modes);

        Modes lastMode;
        Modes nextMode;

        const static int ID = 2;
};

// TODO: Check if I'm allowed to have static variables of the same name in a sub-class
class PreModeChangeEvent: public ModeChangeEvent{
    public:
        PreModeChangeEvent(Modes, Modes);
        const static int ID = 3;
};

class PostModeChangeEvent: public ModeChangeEvent{
    public:
        PostModeChangeEvent(Modes, Modes);
        const static int ID = 4;
};

#endif

