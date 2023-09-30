using namespace vex;

extern brain Brain;
extern controller Controller1;

extern motor flw;
extern motor frw;
extern motor blw;
extern motor brw;

extern motor_group flw_brw;
extern motor_group frw_blw;

extern distance dsF;
extern distance dsR;
extern distance dsB;
extern distance dsL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
