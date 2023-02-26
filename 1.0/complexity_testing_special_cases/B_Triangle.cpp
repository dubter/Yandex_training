#include <iostream>

int main() {
  int first_side;
  int second_side;
  int third_side;
  std::cin >> first_side >> second_side >> third_side;
  if (first_side >= second_side + third_side) {
    std::cout << "NO";
  } else if (second_side >= first_side + third_side) {
    std::cout << "NO";
  } else if (third_side >= first_side + second_side) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }
  return 0;
}