#ifndef _EVENT_ROBOT_TYPES_H_
#define _EVENT_ROBOT_TYPES_H_

#include <vector>

struct IEventBase;
typedef std::vector<IEventBase*> event_list;

// Priority of the handled event
enum class Priorities {
    HIGHEST=0,
    HIGH,
    NORMAL,
    LOW,
    LOWEST
};

enum class Modes {
    ENABLED,
    DISABLED,
    OPERATOR,
    AUTONOMOUS,
    TEST,
    NONE
};

#endif

