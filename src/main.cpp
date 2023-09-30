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

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

double front_prevDist = 0;
double right_prevDist = 0;
double back_prevDist = 0;
double left_prevDist = 0;

// teleop drive
void t_drive (int yPower, int rotPower) {
  flw_brw.setVelocity(yPower - rotPower, pct);
  frw_blw.setVelocity(yPower + rotPower, pct);

  flw_brw.spin(fwd);
  frw_blw.spin(fwd);
}

// autonomous y drive
void a_drive (double yPower) {

}

// autonomous rotation
void a_drive (int rotPower) {

}


// determines if a robot interrupts distance sensors
// returns true if a fluke
bool frontFluke () {
  // get spike in distance
  double dis = dsF.objectDistance(distanceUnits::cm);
  bool flag = false;

  // if there's a spike in distance, there's an object in front
  if (dis > front_prevDist + 0.0) flag = true;

  // for future checks
  front_prevDist = dis;

  wait (20, msec);
  return flag;
}

bool rightFluke () {
  // get spike in distance
  double dis = dsR.objectDistance(distanceUnits::cm);
  bool flag = false;

  // if there's a spike in distance, there's an object in front
  if (dis > front_prevDist + 0.0) flag = true;

  // for future checks
  right_prevDist = dis;

  wait (20, msec);
  return flag;
}

bool backFluke () {
  // get spike in distance
  double dis = dsB.objectDistance(distanceUnits::cm);
  bool flag = false;

  // if there's a spike in distance, there's an object in front
  if (dis > front_prevDist + 0.0) flag = true;

  // for future checks
  back_prevDist = dis;

  wait (20, msec);
  return flag;
}

bool leftFluke () {
  // get spike in distance
  double dis = dsL.objectDistance(distanceUnits::cm);
  bool flag = false;

  // if there's a spike in distance, there's an object in front
  if (dis > front_prevDist + 0.0) flag = true;

  // for future checks
  left_prevDist = dis;

  wait (20, msec);
  return flag;
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {

}

void usercontrol(void) {
  while (1) {

    t_drive(Controller1.Axis2.position(), Controller1.Axis3.position());

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