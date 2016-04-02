#ifndef _EVENT_ROBOT_H_
#define _EVENT_ROBOT_H_

#include <vector>
#include "WPILib.h"
#include "EventBus.h"
#include "handlers/EventHandler.h"
#include "events/EventBase.h"

enum class Modes {
    ENABLED,
    DISABLED,
    OPERATOR,
    AUTONOMOUS,
    TEST,
    NONE
};

class EventRobot: public RobotBase{
    public:
        EventRobot();
        ~EventRobot();
        void registerHandler(EventHandler*);
        void checkForModeChange();
        static EventRobot* getInstance();
        const static EventBus* EVENT_BUS;

        inline Modes getMode(){ return m_mode; };
    protected:
        void StartCompetition() override;
    private:
        static EventRobot* instance;
        std::vector<EventHandler*> handlers;

        Modes m_mode;
};

#endif

