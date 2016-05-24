#ifndef _EVENT_ROBOT_TYPES_H_
#define _EVENT_ROBOT_TYPES_H_

#include <vector>
#include "includes/events/EventBase.h"

typedef std::vector<EventBase*> event_list;

// Priority of the handled event
enum class Priorities {
    HIGHEST=0,
    HIGH,
    NORMAL,
    LOW,
    LOWEST
};

#endif

