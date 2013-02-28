#include "GyroMPU6050.h"
#include "../MPU6050/MPU6050_6Axis_MotionApps20.h"


bool _interrupted  = false;

static void _dataInterrupt() {
  _interrupted = true;  
}

bool GyroMPU6050::init() {
  _interrupted = false;
  
  mpu.initialize();
  if(!mpu.testConnection()) {
    return false;
  }

  if(mpu.dmpInitialize() != 0) {
    return false;
  }

  mpu.setDMPEnabled(true);
  attachInterrupt(0, _dataInterrupt, RISING);
  
  packetSize = mpu.dmpGetFIFOPacketSize();
  ready = true;
  return true;
}

bool GyroMPU6050::isReady() {
  return ready;
}

bool GyroMPU6050::waitForData() {
  _interrupted = false;

  while (!_interrupted && fifoCount < packetSize) {
    delay(0);
  }

  unsigned char status = mpu.getIntStatus();
  fifoCount = mpu.getFIFOCount();

  if(status & 0x10 || fifoCount == 1024) {
    mpu.resetFIFO();
    return false;
  }
  else if(status & 0x02) {
    while (fifoCount < packetSize)
       fifoCount = mpu.getFIFOCount();
    // read a packet from FIFO
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    // track FIFO count here in case there is > 1 packet available
    // (this lets us immediately read more without waiting for an interrupt)
    fifoCount -= packetSize;

    return true;
  }

  return false;
}

bool GyroMPU6050::readQuaternion(QuaternionT& q) {
  Quaternion qt;  

  if(!waitForData())
    return false;

  mpu.dmpGetQuaternion(&qt, fifoBuffer);
  q.w = qt.w;
  q.x = qt.x;
  q.y = qt.y;
  q.z = qt.z;

  return true;
}

bool GyroMPU6050::readEuler(EulerT& e) {
  Quaternion qt;  
  float el[3];

  if(!waitForData())
    return false;

  mpu.dmpGetQuaternion(&qt, fifoBuffer);
  mpu.dmpGetEuler(el, &qt);
  e.psi = el[0] * 180 / M_PI;
  e.theta = el[1] * 180 / M_PI;
  e.phi = el[2] * 180 / M_PI;

  return true;
}

bool GyroMPU6050::readMotion6(Motion6T& m6) {
  mpu.getMotion6(&m6.ax, &m6.ay, &m6.az,
      &m6.gx, &m6.gy, &m6.gz);
  return false;
}

