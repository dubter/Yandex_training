#include <iostream>

int main() {
  int wide1, wide2, length1, length2;
  std::cin >> wide1 >> length1 >> wide2 >> length2;

  int case1 = wide1 + wide2;
  int case2 = length1 + length2;
  int case3 = wide1 + length2;
  int case4 = length1 + wide2;

  int square1 = case1 * std::max(length2, length1);
  int square2 = case2 * std::max(wide2, wide1);
  int square3 = case3 * std::max(wide2, length1);
  int square4 = case4 * std::max(length2, wide1);

  int min_square = std::min(square1, std::min(square2, std::min(square3, square4)));
  if (min_square == square1) {
    std::cout << case1 << " " << std::max(length2, length1);
  } else if (min_square == square2) {
    std::cout << case2 << " " << std::max(wide2, wide1);
  } else if (min_square == square3) {
    std::cout << case3 << " " << std::max(wide2, length1);
  } else {
    std::cout << case4 << " " << std::max(length2, wide1);
  }
  return 0;
}