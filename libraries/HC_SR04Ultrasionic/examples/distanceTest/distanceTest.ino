#include "HC_SR04Ultrasionic.h"

#define TP 8      //Trig_pin
#define EP 9      //Echo_pin

void setup(){
  pinMode(TP,OUTPUT);       // set TP output for trigger  
  pinMode(EP,INPUT);        // set EP input for echo
  Serial.begin(9600);      // initultrasionicultrasionicultrasionicultrasionicHC_SR04UltrasionicHC_SR04UltrasionicHC_SR04Ultrasionic serial 9600
  Serial.println("----------Ultra_Demo_Start-------------------");
}

void loop(){  
  HC_SR04Ultrasionic ultrasionic(TP, EP);
  
  long distacne_cm = ultrasionic.distance(HC_SR04Ultrasionic::CM_MODE);
  Serial.print("Distacne_CM = ");
  Serial.println(distacne_cm);
  delay(300);
}
