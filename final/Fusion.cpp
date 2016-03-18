#include "Fusion.h"
#include <math.h>

Fusion::Fusion(Compass* compass){
	this->compass = compass;
	
}

float Fusion::fuse(long* stepsLeft, long* stepsRight,bool motor, bool upright){
  float rad = compass->getMapAngle(motor, upright);
	float encoder = lastAngle + (*stepsLeft + *stepsRight) * 0.194399f;
  float angle = rad * PI / 180;
  *stepsLeft = 0;
  *stepsRight = 0;
	return fmodf((encoder + angle) / 2.0f, 360);
}
