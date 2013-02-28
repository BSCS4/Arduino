#ifndef GYRO_H
#define GYRO_H 1

typedef struct Quaternion_t {
  float w, x, y, z;
} QuaternionT;

typedef struct Euler_t {
  float psi, theta, phi;
} EulerT;

class Gyro {
public:
  virtual bool init();

  virtual bool readQuaternion(QuaternionT& q);

  virtual bool readEuler(EulerT& e);
};

#endif
