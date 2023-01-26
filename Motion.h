#pragma once
class Ball;

class Motion {
public:
  virtual void update(Ball& b) = 0;
};

