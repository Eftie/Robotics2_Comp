#ifndef DRIVE_H
#define DRIVE_H

#include "vex.h"

using namespace vex;

class drive {

private:
    drive::drive();

    // Individual wheels
    // "w_" means the variable is a wheel
    motor w_flw = motor(PORT1, ratio18_1, false);
    motor w_frw = motor(PORT2, ratio18_1, false);
    motor w_blw = motor(PORT3, ratio18_1, true);
    motor w_brw = motor(PORT4, ratio18_1, true);

    // Left and Right sides
    // the "g_" means the variable is a group
    motor_group g_lft = motor_group(w_flw, w_blw);
    motor_group g_rght = motor_group(w_frw, w_brw);

    // Drivetrain
    drivetrain dt = drivetrain(g_lft, g_rght, 320, 444.5, 130, distanceUnits::mm);

public:
    drive::drive(int32_t leftPower, int32_t rightPower);
};

#endif