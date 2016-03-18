#include "Navigation.h"
#include <Arduino.h>

Navigation::Navigation() {
  for (int angle = 0; angle < 360; angle++) {
    distances[angle] = 0;
  }
}

float Navigation::smallestPositive(float a, float b){
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
float Navigation::getExpectedDistanceToWall(float x, float y, float heading){
	float dX = cos(heading);
	float dY = sin(heading);
	float t0x, t0y, t1x, t1y;
	if(dX == 0){
    Serial.println("Got here");
		t0x = -1;
		t1x = -1;
	}else{
		t0x = (0-x)/dX;
		t1x = (ARENA_WIDTH - x)/dX;
	}
	if(dY == 0){
		t0y = -1;
		t1y = -1;
	}else{
		t0y = (0-y)/dY;
		t1y = (ARENA_LENGTH - y)/dY;
	}
	float t = t0x;
	t = smallestPositive(t,t0y);
	t = smallestPositive(t,t1x);
	t = smallestPositive(t,t1y);
	return t;
}

// fills an array from 0 to 359 with the expected distances at a given point
void Navigation::fillPolarDistanceMap(float x, float y){
	for(int theta = 0; theta < 360; theta ++){
		distances[theta] = getExpectedDistanceToWall(x,y,((float)theta)*PI/180);
	}
}

// Accounts for the angular error of the sensor
float Navigation::getSensorDistanceToWall(int bot_angle) {
  int check_angle;
  float d;
  float closest_d = 400; //400 cm
  for (int angle = bot_angle - 2; angle <= bot_angle + 2; angle++) {
    if (angle > 359) {
      check_angle = 360 - angle;
    } else if (angle < 0) {
      check_angle = 360 + angle;
    } else {
      check_angle = angle;
    }
    d = distances[check_angle];
    if (d < closest_d) {
      closest_d = d;
    }
  }
  return closest_d;
}
