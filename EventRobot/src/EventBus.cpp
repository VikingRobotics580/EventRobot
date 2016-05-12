#include "includes/EventBus.h"
#include "includes/events/EventBase.h"

EventBus::EventBus():
    m_event_list()
{
}

EventBus::~EventBus(){
    for(std::size_t i=0; i<m_event_list.size(); i++)
        delete m_event_list.at(i);
}

void EventBus::post(EventBase* event){
    m_event_list.push_back(event);
}

void EventBus::Update(){
    for(std::size_t i=0; i<m_event_list.size(); i++){
        EventBase* event = m_event_list.at(i);

        // Increase the lifecycle time of the event
        event->lifecycle++;

        // Automatically cancel the event if it is past the maximum allowed time for it to be alive
        if(event->lifecycle > EventBus::MAX_LIFECYCLE_TIME)
            event->canceled = true;
        if(event->canceled){
            m_event_list.erase(m_event_list.begin()+i);
        }
    }
}

