#include "MotionBound.h"
#include "Ball.h"
#include "BallApp.h"

void MotionBound::update(Ball& b)
{
  double dt = b.rap.get();
  b.rap.reset();

  b.ax =0;
  b.ay = 980;
  b.vx += b.ax * dt;
  b.vy += b.ay * dt;
  b.x += b.vx * dt;
  b.y += b.vy * dt;

  if (b.x < 0 || b.x > BallApp::window.getSize().x - 1) {
    b.vx = -b.vx;
    b.x += b.vx * dt;
  }
  if (b.y > BallApp::window.getSize().y - 1) {
    b.vy = -b.vy;
    b.y += b.vy * dt;
  }

  b.theta += b.vtheta * dt;
}
