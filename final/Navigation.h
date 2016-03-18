#ifndef CLASS_NAVIGATION_H
#define CLASS_NAVIGATION_H
#include <math.h>

const float PI = 3.14159;
const float ARENA_WIDTH = 244;		// expected maximum X distance (cm)
const float ARENA_LENGTH = 236;		// expected maximum Y distance (cm)

class Navigation{
	public:
		float getExpectedDistanceToWall(float x, float y, float heading);
		void fillPolarDistanceMap(float x, float y, float distances[]);
}
#endif