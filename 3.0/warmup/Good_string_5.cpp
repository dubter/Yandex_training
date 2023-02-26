#include <iostream>
#include <vector>

int main() {
  size_t n;
  std::cin >> n;
  std::vector<size_t> amounts(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> amounts[i];
  }
  size_t count = 0;
  for (size_t  i = 0; i < n - 1; ++i) {
    count += std::min(amounts[i], amounts[i + 1]);
  }
  std::cout << count;
  return 0;
}