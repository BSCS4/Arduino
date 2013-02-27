#ifndef IR_REMOTE_NEC_RECV_H
#define IR_REMOTE_NEC_RECV_H 1

#include "IRRemoteRecv.h"

class IRRemoteNECRecv : public IRRemoteRecv {

protected:
  bool repeat;
  
  long lastCode;

  bool readRaw(long *code);

public:

  IRRemoteNECRecv(int pin);

  bool isRepeat();
};

#endif

