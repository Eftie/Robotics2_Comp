#include "vex.h"
#include "constants.h"
#include "drive.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller1 = controller(primary);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  if ((Controller1.Axis4.position() < deadband) && (Controller1.Axis1.position() < deadband)) {
    drive(Controller1.Axis4.position(), Controller1.Axis1.position());
  }
}