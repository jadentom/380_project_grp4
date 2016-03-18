#include "Fusion.h"

Fusion::Fusion(Compass* compass){
	this.compass = compass;
	
}

float Fusion::fuse(long* stepsLeft, long* stepsRight,bool motor, bool upright){
	float encoder = lastAngle + (stepsLeft + stepsRight) * 0.194399f;
	return encoder + compass.getAngle(motor, upright);
}