#ifndef CLASS_NAVIGATION_H
#define CLASS_NAVIGATION_H

#include <math.h>
#include <Arduino.h>

const float ARENA_WIDTH = 244;		// expected maximum X distance (cm)
const float ARENA_LENGTH = 236;		// expected maximum Y distance (cm)

class Navigation{
	public:
    // properties
    float distances[360];    

    // methods
    Navigation();
    float smallestPositive(float a, float b);
		float getExpectedDistanceToWall(float x, float y, float heading);
		void fillPolarDistanceMap(float x, float y);
    float getSensorDistanceToWall(int angle);
};
#endif
