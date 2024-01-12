#include "drive.h"

drive::drive() {}

drive::drive(int32_t leftPower, int32_t rightPower) {
    g_lft.setVelocity(leftPower - rightPower, pct);
    g_rght.setVelocity(leftPower + rightPower, pct);

    g_lft.spin(directionType::fwd);
    g_rght.spin(directionType::fwd);

    wait(20, msec);
}