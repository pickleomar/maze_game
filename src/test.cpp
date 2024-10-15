#include <iostream>

int main() {
  int mazeWidth = 10;
  int mazeHeight = 10;

  int Cells[mazeWidth * mazeHeight];
  // Cells = {0};

  for (int i = 0; i < mazeHeight; i++) {
    std::cout << Cells[i] << "\n";
  }

  return 0;
}
