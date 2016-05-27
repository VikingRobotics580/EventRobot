#ifndef _EVENT_ROBOT_H_
#define _EVENT_ROBOT_H_

#include <vector>
#include "WPILib.h"
#include "EventBus.h"
#include "handlers/EventHandler.h"
#include "event_robot_types.h"

/*
enum class Modes {
    ENABLED,
    DISABLED,
    OPERATOR,
    AUTONOMOUS,
    TEST,
    NONE
};
*/

class EventRobot: public RobotBase{
    public:
        EventRobot();
        ~EventRobot();
        void registerHandler(IHandler*);
        void checkForModeChange();
        static EventBus* const EVENT_BUS;

        inline Modes getMode(){ return m_mode; };
    protected:
        void StartCompetition() override;
    private:
        std::vector<IHandler*> m_handlers;

        Modes m_mode;
};

#endif

