/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include "IRRemoteRecv.h"

int RECV_PIN = 11;

IRRemoteRecv recv(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  recv.enable(); // Start the receiver
}

void loop() {
  long r = irecv.read();
  if(r != 0) {
    Serial.println(r, HEX);
  }
}
