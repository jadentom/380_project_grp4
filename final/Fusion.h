#ifndef FUSION_H
#define FUSION_H

#include "Compass.h"

class Fusion{
  private:
    float lastAngle;
	Compass* compass;

  public:
	Fusion(Compass* compass);
	float fuse(long* stepsLeft, long* stepsRight,bool motor, bool upright);
};

#endif