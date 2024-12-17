#include "Timer.h"
#include "raylib.h"
#include <ctime>
#include <fstream>

Timer::Timer() { this->elapsedTime = 0; }

Timer::~Timer() { this->elapsedTime = 0; }

void Timer::startTimer() { this->elapsedTime = 0; }

void Timer::UpdateTimer() { this->elapsedTime += GetFrameTime(); };
void Timer::stopTimer() {
  // Get the current time as a unique identifier
  std::time_t now = std::time(nullptr);
  char timeStr[20];
  std::strftime(timeStr, sizeof(timeStr), "%Y%m%d%H%M%S", std::localtime(&now));

  // Save the elapsed time to a file with a unique key
  // std::ofstream file("./data.ini", std::ios::app);
  // if (file.is_open()) {
  //   file << "ElapsedTime_" << timeStr << "=" << elapsedTime << "\n";
  //   file.close();
  // }
}
float Timer::getElapsedTime() { return elapsedTime; }
