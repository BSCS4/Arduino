#ifndef IR_REMOTE_RECV_H
#define IR_REMOTE_RECV_H 1

#include <IRremote.h>

class IRRemoteRecv {
protected:
  IRrecv *irRecv;

  virtual bool readRaw(long* code);

  virtual long map(long rawCode);

public:
  IRRemoteRecv(int pin);

  ~IRRemoteRecv();

  bool read(long* code);

  void setPin(int pin);

  void enable();
};

#endif

