#include <iostream>

int main() {
  std::string mod;
  int troom, tcond;
  std::cin >> troom >> tcond;
  std::cin >> mod;
  if (mod == "freeze") {
    if (troom >= tcond) {
      std::cout << tcond;
    } else {
      std::cout << troom;
    }
  } else if (mod == "heat") {
    if (tcond >= troom) {
      std::cout << tcond;
    } else {
      std::cout << troom;
    }
  } else if (mod == "auto") {
    std::cout << tcond;
  } else if (mod == "fan") {
    std::cout << troom;
  }
  return 0;
}