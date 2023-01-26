#pragma once
#include "Timer.h"
#include "Motion.h"
#include <SFML/Graphics.hpp>

class Ball {
 public:
  double x, y;
  double vx, vy;
  double ax, ay;

  double theta;
  double vtheta;

  Timer timer;
  Timer rap;

  double life;

  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;

  Motion* motion;

  Ball();
  ~Ball();

  void init();
  void update();
  void draw();
  void clean();

  void setMotion(Motion* m);
};
