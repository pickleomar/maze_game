#include <iostream>
using namespace std;

int main() {
  int arr[10];
  int *ptr;
  int maxVal, minVal;

  cout << "Entrez 10 nombres entiers : " << endl;
  for (ptr = arr; ptr < arr + 10; ptr++) {
    cin >> *ptr;
  }

  maxVal = arr[0];
  minVal = arr[0];

  for (ptr = arr + 1; ptr < arr + 10; ptr++) {
    if (*ptr > maxVal) {
      maxVal = *ptr;
    }
    if (*ptr < minVal) {
      minVal = *ptr;
    }
  }
  cout << "Le plus grand nombre est : " << maxVal << endl;
  cout << "Le plus petit nombre est : " << minVal << endl;

  return 0;
}
