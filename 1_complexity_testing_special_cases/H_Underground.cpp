#include <iostream>

int main() {
  int a, b, n, m;
  std::cin >> a >> b >> n >> m;
  int first_max = 2 * a + a * (n - 1) + n;
  int second_max = 2 * b + b * (m - 1) + m;
  int first_min = a * (n - 1) + n;
  int second_min = b * (m - 1) + m;
  if (first_max < second_min || second_max < first_min) {
    std::cout << -1;
  } else {
    std::cout << std::max(first_min, second_min) << " " << std::min(second_max, first_max);
  }
  return 0;
}