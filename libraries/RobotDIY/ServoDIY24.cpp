/**
Library for www.diy-bot.net 24 channals servo motor controller 
*/

#include <ServoDIY24.h>

int ServoDIY24::set(int channel, int degree) {
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

int ServoDIY24::exec(int msec) {
	if(serialCmd.length() == 0)
		return 0;

  if(!Serial) {
    serialCmd = "";
    return -1;
  }

  serialCmd = String(serialCmd + "T" + msec + "\r\n");
  Serial.print(serialCmd);
  serialCmd = "";
  return 0;
}
