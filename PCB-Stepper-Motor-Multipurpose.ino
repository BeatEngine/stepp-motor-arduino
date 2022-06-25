#include <Ethernet.h>

//#include "A4988.h"

#include <AccelStepper.h>
#include <VariableTimedAction.h>

#define MOTOR_STEPS 200
#define MICROSTEPS 16

#define MOT_U4_DIR A0
#define MOT_U4_STEP A1

#define MOT_U5_DIR A2
#define MOT_U5_STEP A3

//1 == Interface
AccelStepper motA = AccelStepper(1, MOT_U5_STEP, MOT_U5_DIR);
AccelStepper motB = AccelStepper(1, MOT_U4_STEP, MOT_U4_DIR);
//A4988 motB(MOTOR_STEPS,10,MOTOR_STEPS,5,6,11);

int directIon = 1;
int stepsL = 1;
int lc = 0;
void driveLeft()
{
  motA.moveTo(lc);
  motA.runToPosition();
  lc += directIon*stepsL;
  if(lc > 600 || lc < -600)
  {
    lc = stepsL;
    motA.setCurrentPosition(0);
    directIon = -directIon;
  }
}
class LeftWheel : public VariableTimedAction {
private:
  //this method will be called at your specified interval
  unsigned long run() {
    driveLeft();
    return 0;
  }
public:
};
int stepsR = 1;
int rc = 0;
void driveRight()
{
  motB.moveTo(rc);
  motB.runToPosition();
  rc -= directIon*stepsR;
  if(rc < -600 || rc > 600)
  {
    rc = -stepsR;
    motB.setCurrentPosition(0);
    directIon = -directIon;
  }
}

class RightWheel : public VariableTimedAction {
private:
  //this method will be called at your specified interval
  unsigned long run() {
    driveRight();
    return 0;
  }
public:
};


LeftWheel lw;
RightWheel rw;

void setup()
{
  //pinMode(MOT_U5_STEP, OUTPUT);
  //pinMode(MOT_U5_DIR, OUTPUT);
  //pinMode(12, OUTPUT);
  motA.setMaxSpeed(16000);
  motA.setAcceleration(16000);
  motB.setMaxSpeed(16000);
  motB.setAcceleration(16000);

  motB.setPinsInverted(false, false, true);

  lw.start(1);
  rw.start(1);
}


void loop() {
  // Set the target position:
  VariableTimedAction::updateActions();
}
