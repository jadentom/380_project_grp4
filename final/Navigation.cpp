#include "Navigation.h"

float smallestPositive(float a, float b){
	if(a<0 || (b >= 0 && b < a)){
		return b;
	}else{
		return a;
	}
}

/*returns the expected distance from the center of the robot to the wall
x is the x-coordinate of the robot, in cm
y is the y-coordinate of the robot, in cm
heading is the heading of the robot, in radians
It is expected that origin is at base of wall on the side away from ramp, with positive X and Y being towards the ramp and objective respectively
Heading is expected to be measured in radians ccw from the positive X direction
*/
float getExpectedDistanceToWall(float x, float y, float heading){
	float dX = cos(heading);
	float dY = sin(heading);
	float t0x, t0y, t1x, t1y;
	if(dX = 0){
		t0x = -1;
		t1x = -1;
	}else{
		t0x = (0-x)/Dx;
		t1x = (ARENA_WIDTH - x)/Dx;
	}
	if(dY = 0){
		t0y = -1;
		t1y = -1;
	}else{
		t0y = (0-y)/Dy;
		t1y = (ARENA_LENGTH - y)/Dy;
	}
	float t = t0x;
	t = smallestPositive(t,t0y);
	t = smallestPositive(t,t1x);
	t = smallestPositive(t,t1y);
	return t;
}

// fills an array from 0 to 359 with the expected distances at a given point
void fillPolarDistanceMap(float x, float y, float distances[]){
	for(int theta = 0; theta < 360; theta ++){
		distances[theata] = getExpectedDistanceToWall(x,y,((float)theta)*PI/180);
	}
}