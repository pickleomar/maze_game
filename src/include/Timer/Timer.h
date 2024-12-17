#pragma once

class Timer {
public:
  // Constructor
  Timer();
  // Destructor
  ~Timer(); 
  void startTimer();
  void UpdateTimer();
  void stopTimer();
  float getElapsedTime();

private:
  float elapsedTime = 0;
};
