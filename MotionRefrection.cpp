#include "MotionRefrection.h"
#include "Ball.h"
#include "BallApp.h"

void MotionRefrection::update(Ball& b)
{
  double dt = b.rap.get();
  b.rap.reset();

  b.ax = b.ay = 0;
  b.vx += b.ax * dt;
  b.vy += b.ay * dt;
  b.x += b.vx * dt;
  b.y += b.vy * dt;

  if (b.x < 0 || b.x > BallApp::window.getSize().x - 1) {
    b.vx = -b.vx;
    b.x += b.vx * dt;
  }
  if (b.y < 0 || b.y > BallApp::window.getSize().y - 1) {
    b.vy = -b.vy;
    b.y += b.vy * dt;
  }

  b.theta += b.vtheta * dt;
}
