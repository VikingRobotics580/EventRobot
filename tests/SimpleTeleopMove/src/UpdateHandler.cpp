#include <stdio.h>
#include "UpdateHandler.h"

UpdateHandler::UpdateHandler():
    EventHandler()
{
    motor1 = new CANTalon(0);
    motor2 = new CANTalon(1);
    motor3 = new CANTalon(2);
    motor4 = new CANTalon(3);

    m_drive = new RobotDrive(motor1,motor2,motor3,motor4);
    stick1 = new Joystick(0);
    stick2 = new Joystick(1);
}

UpdateHandler::~UpdateHandler(){
    delete stick1;
    delete stick2;

    delete m_drive;

    delete motor1;
    delete motor2;
    delete motor3;
    delete motor4;
}

int UpdateHandler::Update(event_list& events){
    int ret = 0;
    for(auto& event : events){
        if(event->eid == ModeChangeEvent::ID){
            if(((ModeChangeEvent*)event)->nextMode == Modes::OPERATOR){
                ret |= onTeleopInit();
            }else if(((ModeChangeEvent*)event)->nextMode == Modes::DISABLED){
                printf("Disabling...");
            }
        }else if(event->eid == TickEvent::ID && ((TickEvent*)event)->caller->getMode() == Modes::OPERATOR){
            ret |= onTeleopPeriodic();
        }
    }
    return ret;
}

int UpdateHandler::onTeleopInit(){
    printf("TeleopInit...");
    return 0;
}

int UpdateHandler::onTeleopPeriodic(){
    m_drive->TankDrive(stick1->GetX(), stick2->GetX());
    return 0;
}

