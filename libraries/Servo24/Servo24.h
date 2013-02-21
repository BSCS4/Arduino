/**
Library for www.diy-bot.net 24 channals servo motor controller 
*/

#include <Arduino.h>

class Servo24 {
  String serialCmd = "";
public:
	/** Get ready to receive the command, clear the command set.*/
  void ready();

	/** Set degree of servo motor, just buffer to the command set, not do it right now.
	*/
  int set(int channel, int degree);
  
	/**Execute the command set.
	*/
  int exec(int msec);
};

