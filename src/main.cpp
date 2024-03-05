/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

// A global instance of competition
competition Competition;

// drivetrain
motor w_backLeft = motor(PORT12, ratio18_1, false);
motor w_frontLeft = motor(PORT15, ratio18_1, true);
motor w_backRight = motor(PORT14, ratio18_1, true);
motor w_frontRight = motor(PORT13, ratio18_1, false);

// ball control
motor shooter = motor(PORT16, ratio6_1, false);
motor intake = motor(PORT17, ratio18_1, false);

// end game
motor climber = motor(PORT18, ratio36_1, true);

controller c = controller(primary);


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  w_backLeft.setStopping(vex::brakeType::brake);
  w_frontLeft.setStopping(vex::brakeType::brake);
  w_backRight.setStopping(vex::brakeType::brake);
  w_frontRight.setStopping(vex::brakeType::brake);

  shooter.setStopping(vex::brakeType::coast);
  intake.setStopping(vex::brakeType::coast);

  climber.setStopping(vex::brakeType::brake);

  shooter.setVelocity(100, vex::percentUnits::pct);
  intake.setVelocity(30, vex::percentUnits::pct);
  climber.setVelocity(100, velocityUnits::pct);

}

void autonomous(void) {

}

void usercontrol(void) {
  while (1) {

    int fwd = c.Axis3.position();
    int rot = c.Axis1.position();
    
    // intake functionality
    if (c.ButtonL2.pressing()) {
      intake.spin(vex::directionType::fwd);
    } else if (c.ButtonL1.pressing()) {
      intake.spin(vex::directionType::rev);
    } else {
      intake.stop();
    }

    // shooter functionality
    if (c.ButtonR2.pressing()) {
      shooter.spin(vex::directionType::fwd);
    } else if (c.ButtonR1.pressing()) {
      shooter.spin(vex::directionType::rev);
    } else {
      shooter.stop();
    }
    
    // climber functionality
    if (c.ButtonUp.pressing()) {
      climber.spin(vex::directionType::fwd);
    } else if (c.ButtonDown.pressing()) {
      climber.spin(vex::directionType::rev);
    } else {
      climber.stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}