#include "EventBus.h"
#include "events/EventBase.h"

EventBus::EventBus():
    event_list()
{
}

EventBus::~EventBus(){
    for(int i=0; i<event_list.size(); i++)
        delete event_list.at(i);
}

void EventBus::post(EventBase* event){
    event_list.push_back(event);
}

void EventBus::Update(){
    for(int i=0; i<event_list.size(); i++){
        EventBase* event = event_list.at(i);

        // Increase the lifecycle time of the event
        event->lifecycle++;

        // Automatically cancel the event if it is past the maximum allowed time for it to be alive
        if(event->lifecycle > EventBus::MAX_LIFECYCLE_TIME)
            event->setCanceled(true);
        if(event->isCanceled()){
            delete event_list.remove(i);
        }
    }
}

