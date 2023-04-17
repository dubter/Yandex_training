#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, int> points;
  int x, y;
  int min_x, max_x;
  std::cin >> x >> y;
  points[x] = y;
  min_x = max_x = x;
  for (int i = 1; i < n; ++i) {
    std::cin >> x >> y;
    points[x] = y;

    if (min_x > x) {
      min_x = x;
    }
    if (max_x < x) {
      max_x = x;
    }
  }

  int sum = max_x + min_x;
  bool ans = true;
  for (auto it = points.begin(); it != points.end(); ++it) {
    if (points.find(sum - it->first) == points.end() || points[sum - it->first] == points[it->first]) {
      ans = false;
      break;
    }
  }

  std::cout << ans;
  return 0;
}