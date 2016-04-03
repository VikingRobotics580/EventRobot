#ifndef _EVENT_ROBOT_H_
#define _EVENT_ROBOT_H_

#include <vector>
#include "WPILib.h"
#include "EventBus.h"
#include "handlers/EventHandler.h"
#include "handlers/RobotHandler.h"

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
        static EventBus* const EVENT_BUS;

        inline Modes getMode(){ return m_mode; };
    protected:
        void StartCompetition() override;
    private:
        std::vector<EventHandler*> m_handlers;

        Modes m_mode;
};

#endif

