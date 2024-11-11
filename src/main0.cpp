#include <iostream>

int main() {
  int lines = 10;

  for (int i = 0; i <= lines; i++) {

    for (int k = lines - i; k > 0; k--) {
      std::cout << "  ";
    }
    for (int j = 0; j < (i * 2) + 1; j++) {
      std::cout << "* ";
    }

    std::cout << "\n";
  }

  return 0;
}
