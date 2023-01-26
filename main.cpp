#include <exception>
#include <iostream>
#include "Timer.h"
#include "BallApp.h"

using namespace std;

int main()
{
  App* app;

  app = new BallApp();
  dynamic_cast<BallApp*>(app)->setNBalls(10);

  app->init();

  while (app->isActive()){
    app->event();
    app->update();
    app->draw();
    app->waitSync();
  }

  app->clean();

  delete app;
}

