#include "IRRemoteNECRecv.h"
#include <Arduino.h>

IRRemoteNECRecv::IRRemoteNECRecv(int pin) : IRRemoteRecv(pin) {
  repeat = false;
  lastCode = 0;
}

bool IRRemoteNECRecv::readRaw(long *code) {
  if(!IRRemoteRecv::readRaw(code)) {
    return false;
  }

  if(*code == 0xFFFFFFFF) {
    *code = lastCode;
    repeat = true;
  }
  else {
    lastCode = *code;
    repeat = false;
  }

  return true;
}

bool IRRemoteNECRecv::isRepeat() {
  return repeat;
}
