#include <iostream>
int s = 0;
void call() {
  s++;
  return;
}
int recall = 0;
int main() {

  call();
  while (true) {
    std::cout << "appel numéro : " << s << "\n";
    std::cout << "Enter 1 to recall function ";
    std::cin >> recall;
    if (recall == 0) {
      break;
    } else {
      call();
      continue;
    }
  }

  return 0;
}
