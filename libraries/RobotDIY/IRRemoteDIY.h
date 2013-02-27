#ifndef IR_REMOTE_DIY_H
#define IR_REMOTE_DIY_H 1

#include <Arduino.h>
#include "../IRRemoteComm/IRRemoteRecv.h"
#include "../IRRemoteComm/IRRemoteNECRecv.h"

class IRRemoteDIY : public IRRemoteNECRecv {
public:
  static const long KEY_NONE = 0;
  static const long KEY_MENU = 1;
  static const long KEY_TEST = 2;
  static const long KEY_PLUS = 3;
  static const long KEY_RETURN = 4;
  static const long KEY_BACKWARD = 5;
  static const long KEY_PLAY = 6;
  static const long KEY_FORWARD = 7;
  static const long KEY_0 = 8;
  static const long KEY_MINUS = 9;
  static const long KEY_C = 10;
  static const long KEY_1 = 11;
  static const long KEY_2 = 12;
  static const long KEY_3 = 13;
  static const long KEY_4 = 14;
  static const long KEY_5 = 15;
  static const long KEY_6 = 16;
  static const long KEY_7 = 17;
  static const long KEY_8 = 18;
  static const long KEY_9 = 19;
  static const long KEY_POWER = 20;

  IRRemoteDIY(int pin) : IRRemoteNECRecv(pin) { }

protected:
  virtual long map(long code);
};

#endif
