#include <iostream>

int Multiple_2(int number) {
  if (number % 2 == 0) {
    std::cout << "il est pair \n";
    return 1;
  } else {
    return 0;
  }
}

int Multiple_3(int number) {
  if (number % 3 == 0) {
    std::cout << "il est multiple de 3 \n";
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int number;
  while (1) {
    std::cout << "donnez un entier : ";
    std::cin >> number;

    int multipe_2 = Multiple_2(number);
    int multipe_3 = Multiple_3(number);

    if (multipe_2 && multipe_3) {

      std::cout << "il est divisible par 6\n";
    }
    std::cout << "----------------------------\n";
  }
  return 0;
}
