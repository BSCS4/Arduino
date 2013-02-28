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
  /**
  Initialize the gyroscope.
  @return false for failed, true for okay.
  */
  virtual bool init();

  /**
  Read Quaternion (w, x, y z).
  @param q Quaternion be wroted to.
  @return false for failed, true for okay.
  */
  virtual bool readQuaternion(QuaternionT& q);
  
  /**
  Read Euler angles with degree.
  @param e Euler be wroted to.
  @return false for failed, true for okay.
  */
  virtual bool readEuler(EulerT& e);
};

#endif
