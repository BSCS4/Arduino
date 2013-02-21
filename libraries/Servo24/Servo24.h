/**
Library for www.diy-bot.net 24 channals servo motor controller 
*/

#include <Arduino.h>

class Servo24 {
String serialCmd;
public:

	Servo24() {
		serialCmd = "";
	}
	
	/** Set degree of servo motor, just buffer to the command set, not do it right now.
	@param channel 1-24 channel of servo motor;
	@param degree 1-180 degree of servo motor;
	@return -1 for false, 0 for success.
	*/
	int set(int channel, int degree);
  
	/**Execute the command set, and clear the command set.
	@param msec set the execution time with micro-second
	@return -1 for false, 0 for success.
	*/
	int exec(int msec);
};

