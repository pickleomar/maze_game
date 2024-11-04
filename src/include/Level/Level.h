#pragma once

#define EASY 001
#define MEDIUM 010
#define HARD 011
#define IMPOSSIBLE 100

class Level {
public:
  void setLevel(int level);
  int getLevel();

private:
  int level = EASY;
};
