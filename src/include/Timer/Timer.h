#pragma once

class Timer {
public:
  void startTimer(float lifeTime);
  void UpdateTimer();
  bool timerDone();

private:
  float timout;
  float lifeTime = 0;
};
