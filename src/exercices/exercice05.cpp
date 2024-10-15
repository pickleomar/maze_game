#include <iostream>

int main() {
  int a = 0;
  int &ref_a = a;
  int *p_a = &a;
  std::cout << "a : " << a << "\n";
  std::cout << "ref_a : " << ref_a << "\n";
  std::cout << "p_a : " << p_a << "\n";

  return 0;
}
