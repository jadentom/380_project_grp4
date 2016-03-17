

#define LEFT_ENCODER_PIN 18
#define RIGHT_ENCODER_PIN 2

class Encoders {
  public:

    // properties
    float left_period;
    float left_freq;
    float right_period;
    float right_freq;
    
    unsigned long prev_left; 
    unsigned long prev_right;

    // methods
    Encoders();
    void leftTrigger();
    void rightTrigger();
};

extern Encoders encoders;

