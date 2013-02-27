#include "IRRemoteRecv.h"

IRRemoteRecv::IRRemoteRecv(int pin) {
  irRecv = new IRrecv(pin);
}

IRRemoteRecv::~IRRemoteRecv() {
  delete irRecv;
}

bool IRRemoteRecv::readRaw(long *code) {
  decode_results res;

  if(irRecv->decode(&res)) {
    irRecv->resume();
    *code = res.value;
    return true;
  }

  return false;
}

bool IRRemoteRecv::read(long *code) {
  if(readRaw(code)) {
    *code = map(*code);
    return true;
  }

  return false; 
}

void IRRemoteRecv::enable() {
  irRecv->enableIRIn();
}

long IRRemoteRecv::map(long code) {
  return code;
}
