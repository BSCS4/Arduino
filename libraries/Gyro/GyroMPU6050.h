#ifndef GYRO_MPU_6050_H
#define GYRO_MPU_6050_H 1

#include "GyroMotion6.h"
#include <I2Cdev.h>

#define MPU6050_INCLUDE_DMP_MOTIONAPPS20
#include <../MPU6050/MPU6050.h>


class GyroMPU6050: public GyroMotion6 {
  uint16_t packetSize;
  unsigned short fifoCount;
  bool ready;
  unsigned char fifoBuffer[64];

  MPU6050 mpu;

public:

  GyroMPU6050() {
    ready = false;
    fifoCount = 0;
    packetSize = 0;
  }

  virtual bool init();

  bool waitForData();

  virtual bool readQuaternion(QuaternionT& q);

  virtual bool readEuler(EulerT& e);

  virtual bool readMotion6(Motion6T& m6);

  bool isReady();
};

#endif
