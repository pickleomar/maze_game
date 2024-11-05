#include <cmath>
#include <iostream>

template <typename T> class NombreComplexe {
private:
  T reel;
  T imaginaire;

public:
  // Constructeurs
  NombreComplexe(T r = 0, T i = 0) : reel(r), imaginaire(i) {}

  // Getters pour reel et imaginaire
  T getReel() const { return reel; }
  T getImaginaire() const { return imaginaire; }

  // Opérateurs arithmétiques
  NombreComplexe operator+(const NombreComplexe &autre) const {
    return NombreComplexe(reel + autre.reel, imaginaire + autre.imaginaire);
  }

  NombreComplexe operator-(const NombreComplexe &autre) const {
    return NombreComplexe(reel - autre.reel, imaginaire - autre.imaginaire);
  }

  NombreComplexe operator*(const NombreComplexe &autre) const {
    return NombreComplexe(reel * autre.reel - imaginaire * autre.imaginaire,
                          reel * autre.imaginaire + imaginaire * autre.reel);
  }

  NombreComplexe operator/(const NombreComplexe &autre) const {
    T denominateur =
        autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;
    return NombreComplexe(
        (reel * autre.reel + imaginaire * autre.imaginaire) / denominateur,
        (imaginaire * autre.reel - reel * autre.imaginaire) / denominateur);
  }

  // Opérateurs de comparaison
  bool operator==(const NombreComplexe &autre) const {
    return (reel == autre.reel && imaginaire == autre.imaginaire);
  }

  bool operator!=(const NombreComplexe &autre) const {
    return !(*this == autre);
  }

  // Fonctions amies pour l'affichage et la surcharge des opérateurs de flux
  friend std::ostream &operator<<(std::ostream &os,
                                  const NombreComplexe &nombre) {
    os << nombre.reel << " + " << nombre.imaginaire << "i";
    return os;
  }

  friend std::istream &operator>>(std::istream &is, NombreComplexe &nombre) {
    is >> nombre.reel >> nombre.imaginaire;
    return is;
  }
};

int main() {
  NombreComplexe<double> z1(3.0, 4.0);
  NombreComplexe<double> z2(1.0, 2.0);

  // Tests des opérateurs arithmétiques
  std::cout << "z1 + z2 = " << (z1 + z2) << std::endl;
  std::cout << "z1 - z2 = " << (z1 - z2) << std::endl;
  std::cout << "z1 * z2 = " << (z1 * z2) << std::endl;
  std::cout << "z1 / z2 = " << (z1 / z2) << std::endl;

  // Tests des opérateurs de comparaison
    std::cout << "z1 == z2: " << (z1 == z2 ? "true" : "
