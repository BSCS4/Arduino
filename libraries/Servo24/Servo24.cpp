/**
Library for www.diy-bot.net 24 channals servo motor controller 
*/

#include "Servo24.h"

void Servo24::ready() {
	serialCmd = "";
}

int Servo24::set(int channel, int degree) {
	if(channel < 1 || channel > 24) 
		return -1;

	if(degree < 0)
		degree = 0;

	if(degree >180)
		degree = 180;

	long p = (degree * 2000l) / 180 + 500;
	serialCmd = String(serialCmd + "#" + channel + "P" + p);
	return 0;
}

int Servo24::exec(int msec) {
	if(!Serial)
		return -1;

	serialCmd = String(serialCmd + "T" + msec + "\r\n");
	Serial.print(serialCmd);
	return 0;
}
