#pragma once
#include <utility>
using std::pair;

class Player {
public:
  pair<int, int> getPosition();

private:
  pair<int, int> position;
};
