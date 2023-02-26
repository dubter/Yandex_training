#include <iostream>
#include <vector>

int main() {
  int x, y, z;
  std::cin >> x >> y >> z;
  int num;
  std::cin >> num;

  std::vector<int> digits(10, 0);
  while (num > 0) {
    digits[num % 10] += 1;
    num /= 10;
  }
  int count = 0;
  for (int i = 0; i < digits.size(); ++i) {
    if (i != x && i != y && i != z && digits[i] != 0) {
      count++;
    }
  }
  std::cout << count;
  return 0;
}