/**
 Ultrasonic Ranging
 Library for HC-SR04 Ultrasonic Ranging Module.librar
*/

class HC_SR04Ultrasionic {

  int trigPin, echoPin;
public:
  static const int INCH_MODE = 0;
  static const int CM_MODE = 1;

  HC_SR04Ultrasionic(int trigPin, int echoPin);

  long distance(int inchMode);
};
