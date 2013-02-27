#include <IRRemoteDIY.h>
#include <IRRemoteNECRecv.h>

long IRRemoteDIY::map(long code) {
  code = (0x0FFFF & code) >> 8;
//  Serial.println(code);
  switch(code) {
  case 162:
    return KEY_POWER;
  case 226:
    return KEY_MENU;
  case 34:
    return KEY_TEST;
  case 2:
    return KEY_PLUS;
  case 194:
    return KEY_RETURN;
  case 224:
    return KEY_BACKWARD;
  case 168:
    return KEY_PLAY;
  case 144:
    return KEY_FORWARD;
  case 104:
    return KEY_0;
  case 152:
    return KEY_MINUS;
  case 176:
    return KEY_C;
  case 48:
    return KEY_1;
  case 24:
    return KEY_2;
  case 122:
    return KEY_3;
  case 16:
    return KEY_4;
  case 56:
    return KEY_5;
  case 90:
    return KEY_6;
  case 66:
    return KEY_7;
  case 74:
    return KEY_8;
  case 82:
    return KEY_9;
  }

  return KEY_NONE;
}
