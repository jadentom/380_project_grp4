class MotorControl{
  private:
    /*
    // Pins - Digital Pins (Controls Direction)
    const int LEFT_DIGITAL_PIN = 44;
    const int RIGHT_DIGITAL_PIN = 42;

    // Pins - PWM Pins (Controls Speed)
    const int LEFT_PWM_PIN = 5;
    const int RIGHT_PWM_PIN = 4;
    */

    bool isUpsideDown = false;


  public:
    MotorControl();
    void spinRight(int speed);
    void spinLeft(int speed);
    void setUpsideDown();
    void spinCW(int speed);
    void spinCCW(int speed);
    void forward(int speed);
    void backward(int speed);
    void stop();
};
