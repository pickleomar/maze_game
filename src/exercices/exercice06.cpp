#include <iostream>

void incrementer(int &a) { a++; }
void permuter(int &a, int &b) {
  int c = b;
  b = a;
  a = c;
}

int main() {
  int a = 10;
  int b = 0;

  incrementer(a);
  permuter(a, b);

  std::cout << "a : " << a << "\n";
  std::cout << "b : " << b << "\n";

  return 0;
}
