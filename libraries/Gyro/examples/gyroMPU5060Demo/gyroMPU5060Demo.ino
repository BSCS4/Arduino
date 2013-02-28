
#include "Wire.h"
#include "I2Cdev.h"
#include "GyroMPU6050.h"
#include "MPU6050.h"

GyroMPU6050 gyro;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
   if(gyro.init()) {
    Serial.println("Initializing ok...");
   }
}

void loop() {  
  /*Motion6T m6;
  gyro.readMotion6(m6);
  
    Serial.print(m6.gx); 
    Serial.print("\t");
    Serial.print(m6.gy); 
    Serial.print("\t");
    Serial.println(m6.gz);
    */
    
 EulerT e;
  gyro.readEuler(e);
  
    Serial.print(e.psi); 
    Serial.print("\t");
    Serial.print(e.theta); 
    Serial.print("\t");
    Serial.println(e.phi); 
  
}
