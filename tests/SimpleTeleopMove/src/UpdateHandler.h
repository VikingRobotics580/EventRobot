#ifndef _UPDATE_HANDLER_H_
#define _UPDATE_HANDLER_H_
#include "WPILib.h"
#include "handlers/EventHandler.h"

class UpdateHandler: public EventHandler {
    public:
        UpdateHandler();
        ~UpdateHandler();

        int Update(event_list&) override;

    protected:
        int onTeleopInit();
        int onTeleopPeriodic();

    private:
        RobotDrive* m_drive;

        CANTalon* motor1;
        CANTalon* motor2;
        CANTalon* motor3;
        CANTalon* motor4;

        Joystick* stick1;
        Joystick* stick2;
};

#endif

