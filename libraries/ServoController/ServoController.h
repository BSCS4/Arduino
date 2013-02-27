/**
Library for servo motor controller 
*/

#ifndef SERVO_CONTROLLER
#define SERVO_CONTROLLER 1

class ServoController {
public:
  /** Set degree of servo motor, just buffer to the command set, not do it right now.
  @param channel channel NO. of servo motor;
  @param degree degree of servo motor;
  @return -1 for false, 0 for success.
  */
  virtual int set(int channel, int degree);
  
  /**Execute the command set, and clear the command set.
  @param msec set the execution time with micro-second
  @return -1 for false, 0 for success.
  */
  virtual int exec(int msec);
};

#endif

