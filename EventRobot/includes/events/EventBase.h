#ifndef _EVENT_BASE_H_
#define _EVENT_BASE_H_

typedef struct struct_EventBase {
        int eid;
        int lifecycle;

        bool m_canceled;
} EventBase;

#endif

