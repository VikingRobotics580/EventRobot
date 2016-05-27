#ifndef _EVENT_BASE_H_
#define _EVENT_BASE_H_

struct IEventBase{};

template<typename T>
struct EventBase: public IEventBase {
        int eid;
        int lifecycle;
        bool canceled;

        inline T* getActualType(){
            return static_cast<T*>(this);
        }
};

#endif

