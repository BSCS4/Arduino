#include "HC_SR04Ultrasionic.h"
#include "Arduino.h"

HC_SR04Ultrasionic::HC_SR04Ultrasionic(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
}

long HC_SR04Ultrasionic::distance(int inchMode) {
  digitalWrite(trigPin, LOW);                    
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                 // pull the Trig pin to high level for more than 10us impulse 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long microseconds = pulseIn(echoPin, HIGH);   // waits for the pin to go HIGH, and returns the length of the pulse in microseconds

  if(inchMode == CM_MODE)	
    return microseconds / 29 / 2;
  return microseconds / 74 / 2;
}
