#include <iostream>

int main() {
  int taille;
  int *tableau;
  int *tableau2;
  std::cout << "Entrez la taille du tableau :";
  std::cin >> taille;

  tableau = new int[taille];
  tableau2 = new int[taille];

  for (int i = 0; i < taille; i++) {
    std::cout << "Entrez la valeur " << i << " dans le tableau : ";
    std::cin >> tableau[i];
  }

  for (int i = 0; i < taille; i++) {
    tableau2[i] = tableau[i] * tableau[i];
  }

  delete tableau;

  std::cout << "Les Valeur de tableau 2 sont : \n";
  for (int i = 0; i < taille; i++) {
    std::cout << tableau2[i] << "\n";
  }

  return 0;
}
