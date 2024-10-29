#include "Timer.h"
#include "raylib.h"

void Timer::startTimer(float lifeTime) { this->lifeTime = lifeTime; }

void Timer::UpdateTimer() {
  if (this->lifeTime > 0)
    this->lifeTime -= GetFrameTime();
};

bool Timer::timerDone() { return lifeTime <= 0; }
