#ifndef _EVENT_BASE_H_
#define _EVENT_BASE_H_

class EventBus;

class EventBase {
    public:
        EventBase();
        ~EventBase();
        inline bool isCanceled(){ return m_canceled; }
        inline void setCanceled(bool value){ m_canceled = value; }

        int eid;
        int lifecycle;

    private:
        bool m_canceled;

    friend class EventBus;
};

#endif

