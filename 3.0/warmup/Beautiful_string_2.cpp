#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int k;
  std::cin >> k;
  std::string string;
  std::cin >> string;

  std::unordered_map<char, std::vector<int>> distance_equal_symbols;
  for (int i = 0; i < string.size(); ++i) {
    distance_equal_symbols[string[i]].push_back(i);
    if (distance_equal_symbols[string[i]].size() > 1) {
      distance_equal_symbols[string[i]][distance_equal_symbols[string[i]].size() - 2] = i - distance_equal_symbols[string[i]][distance_equal_symbols[string[i]].size() - 2];
    }
  }

  for (auto &positions : distance_equal_symbols) {
    positions.second.erase(positions.second.end() - 1);
    std::sort(positions.second.begin(), positions.second.end());
  }

  int max = 0;
  for (auto &positions : distance_equal_symbols) {
    int sum = 0;
    int i = -1;
    while (i < static_cast<int>(positions.second.size()) - 1 && sum <= k) {
      ++i;
      sum += positions.second[i];
    }
    if (sum > k) {
      sum -= positions.second[i];
    }
    sum += k - sum + 1;
    max = std::max(max, std::min(sum, static_cast<int>(string.size())));
  }
  std::cout << max;
  return 0;
}