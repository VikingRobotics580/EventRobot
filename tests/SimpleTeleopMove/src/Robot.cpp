#include "Robot.h"
#include "WPILib.h"
#include "UpdateHandler.h"

Robot::Robot():
    EventRobot()
{
    registerHandler(new UpdateHandler());
}

Robot::~Robot(){
}

START_ROBOT_CLASS(Robot);

