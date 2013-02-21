#include "Servo24.h"

void setup() {
	Serial.begin(115200);
	while(!Serial) {
	}
}

void loop() {

	Servo24 controller;

	//set the No.1 servo motor to 0 degree.
	controller.set(1, 0);
	//set the No.24 servo motor to 0 degree.
	controller.set(24, 0);
	//execute the command set(with 2 commands) in 1 second.
	controller.exec(1000);
	//waiting for controller done the job.
	delay(1000);

	//set the No.1 servo motor to 180 degree.
	controller.set(1, 180);
	//set the No.24 servo motor to 180 degree.
	controller.set(24, 180);
	//execute the command set(with 2 commands) in 200 micro-second.
	controller.exec(200);
	delay(1000);
}
