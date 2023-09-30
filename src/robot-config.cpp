#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller1 = controller(primary);

motor flw = motor(PORT1, ratio18_1, false);;
motor frw = motor(PORT2, ratio18_1, false);
motor blw = motor(PORT3, ratio18_1, true);
motor brw = motor(PORT4, ratio18_1, true);

motor_group lft = motor_group(flw, blw);
motor_group rght = motor_group(frw, brw);

motor_group flw_brw = motor_group(flw, brw);
motor_group frw_blw = motor_group(frw, blw);

distance dsF = distance(PORT5);
distance dsR = distance(PORT6);
distance dsB = distance(PORT7);
distance dsL = distance(PORT8);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}