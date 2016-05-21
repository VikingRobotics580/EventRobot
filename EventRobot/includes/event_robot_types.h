#ifndef _EVENT_ROBOT_TYPES_H_
#define _EVENT_ROBOT_TYPES_H_

#include <vector>
#include <map>
#include "includes/events/EventBase.h"
#include "includes/events/EventRobot.h"
#include "includes/events/EventHandler.h"

typedef std::vector<EventBase*> event_list;
typedef std::map<HandlerPriority,std::vector<EventHandler*> > handlermap;

#endif

