#include <iostream>
#include <vector>

int main() {
  int k;
  std::cin >> k;
  int x, y;
  std::cin >> x >> y;
  int min_x = x, min_y = y, max_x = x, max_y = y;
  for (int i = 1; i < k; ++i) {
    std::cin >> x >> y;
    min_x = std::min(min_x, x);
    max_x = std::max(max_x, x);

    min_y = std::min(min_y, y);
    max_y = std::max(max_y, y);
  }

  std::cout << min_x << " ";
  std::cout << min_y << " ";
  std::cout << max_x << " ";
  std::cout << max_y << " ";
  return 0;
}