#include "MotionStop.h"
#include "Ball.h"
#include "BallApp.h"

void MotionStop::update(Ball& b)
{
  double dt = b.rap.get();
  b.rap.reset();

  b.theta += b.vtheta * dt;
}
