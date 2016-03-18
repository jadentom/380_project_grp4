#ifndef ENCODERS_H
#define ENCODERS_H

#define LEFT_ENCODER_PIN_A 19
#define LEFT_ENCODER_PIN_B 18
#define RIGHT_ENCODER_PIN_A 3
#define RIGHT_ENCODER_PIN_B 2

class Encoders {
  public:

    // properties
	float left_rate, right_rate;
	long left_sum, right_sum,
		left_periodStart, right_periodStart;
	bool left_aSet, right_aSet,
		left_bSet, right_bSet;

    // methods
    Encoders();
    void leftTriggerA();
    void rightTriggerA();
    void leftTriggerB();
    void rightTriggerB();

    void triggerA(bool& aSet, bool& bSet, int pinA, long& periodStart, long& sum, float& rate);
    void triggerB(bool& bSet);
};

extern Encoders encoders;

#endif
