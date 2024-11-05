#include <iostream>

template <typename T> class Complex {

public:
  Complex(T reel, T imag) : reel(reel), imaginaire(imag) {};

  T getReel() { return reel; }
  T getImaginaire() { return imaginaire; }

private:
  T reel;
  T imaginaire;
};

class NombreComplexe : public Complex<int> {
public:
  NombreComplexe(int reel, int imag) : Complex<int>(reel, imag) {};

  void afficher() {
    if (getImaginaire() < 0)
      std::cout << getReel() << " - " << getImaginaire() * -1 << "i" << "\n";
    else
      std::cout << getReel() << " + " << getImaginaire() << "i" << "\n";
  }

  NombreComplexe operator+(NombreComplexe &autre) {
    return NombreComplexe(getReel() + autre.getReel(),
                          getImaginaire() + autre.getImaginaire());
  }

  NombreComplexe operator-(NombreComplexe &autre) {
    return NombreComplexe(getReel() - autre.getReel(),
                          getImaginaire() - autre.getImaginaire());
  }

  NombreComplexe operator*(NombreComplexe &autre) {
    return NombreComplexe(getReel() * autre.getReel(),
                          getImaginaire() * autre.getImaginaire());
  }

  NombreComplexe operator/(NombreComplexe &autre) {
    if (autre.getReel() == 0 || autre.getImaginaire() == 0) {
      std::cout << "On ne peut pas diviser par 0 \n;";
      return NombreComplexe(0, 0);
    } else
      return NombreComplexe(getReel() / autre.getReel(),
                            getImaginaire() / autre.getImaginaire());
  }

  bool operator>=(NombreComplexe &autre) {
    return getReel() >= autre.getReel() &&
           getImaginaire() >= autre.getImaginaire();
  }
  bool operator>(NombreComplexe &autre) {
    return getReel() > autre.getReel() &&
           getImaginaire() > autre.getImaginaire();
  }

  bool operator<=(NombreComplexe &autre) {
    return getReel() <= autre.getReel() &&
           getImaginaire() <= autre.getImaginaire();
  }
  bool operator<(NombreComplexe &autre) {
    return getReel() < autre.getReel() &&
           getImaginaire() < autre.getImaginaire();
  }
  bool operator==(NombreComplexe &autre) {
    return getReel() == autre.getReel() &&
           getImaginaire() == autre.getImaginaire();
  }

  bool operator!=(NombreComplexe &autre) {
    return getReel() != autre.getReel() ||
           getImaginaire() != autre.getImaginaire();
  }
};

int main() {

  NombreComplexe num1(-5, -10);
  NombreComplexe num2(5, 10);
  NombreComplexe num3(5, 10);

  num1.afficher();
  num2.afficher();

  std::cout << "Addition : \n";
  num3 = num1 + num2;
  num3.afficher();
  std::cout << "Soustraction : \n";

  num3 = num1 - num2;
  num3.afficher();

  std::cout << "Multiplication : \n";

  num3 = num1 * num2;
  num3.afficher();

  std::cout << "Division : \n";

  num3 = num1 / num2;
  num3.afficher();

  bool test = num1 > num2;
  bool test2 = num1 < num2;
  bool test3 = num1 <= num2;
  bool test4 = num1 >= num2;
  bool test5 = num1 != num2;
  bool test6 = num1 == num2;

  return 0;
}
