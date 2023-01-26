#include "BallApp.h"
#include "Timer.h"
#include "MotionRefrection.h"
#include "MotionBound.h"
#include "MotionStop.h"

BallApp::BallApp()
{
  nballs = 0;
  setKeyboardListener(this);
  setMouseListener(this);
}

BallApp::~BallApp()
{
}

void BallApp::init()
{
  balls.resize(nballs);     // 画面に表示するボールの個数

  for (auto& b : balls) {
    b.init();
    b.setMotion(new MotionRefrection);
  }
}

void BallApp::update()
{
  for (auto& b : balls)
    b.update();
}

void BallApp::draw()
{
  window.clear(sf::Color::White);

  for (auto& b : balls)
    b.draw();

  window.display();
}

void BallApp::clean()
{
  for (auto& b : balls)
    b.clean();
}  

void BallApp::onKeyDown(sf::Keyboard::Key key)
{
  switch (key) {
  case sf::Keyboard::Z:
    for (auto& b : balls)
      b.setMotion(new MotionRefrection);
    break;
    
  case sf::Keyboard::X:
    for (auto& b : balls)
      b.setMotion(new MotionBound);
    break;

  case sf::Keyboard::C:
    for (auto& b : balls)
      b.setMotion(new MotionStop);
    break;

  case sf::Keyboard::Escape:
    window.close();
    break;
  }

}

void BallApp::onMouseMoved(sf::Event::MouseMoveEvent mouse)
{
}

void BallApp::onClick(sf::Event::MouseButtonEvent mouse)
{
}

void BallApp::offClick(sf::Event::MouseButtonEvent mouse)
{
}

void BallApp::setNBalls(int n)
{
  nballs = n;
}
