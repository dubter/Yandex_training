#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int k;
  std::cin >> k;
  std::string str;
  std::cin >> str;

  std::vector<int> countSymbol(str.size() + 1);
  long max = 0;
  for (char symbol = 'a'; symbol < 'z'; ++symbol) {
    countSymbol[0] = 0;
    for (int i = 1; i < str.size() + 1; ++i) {
      if (str[i - 1] != symbol) {
        countSymbol[i] = countSymbol[i - 1] + 1;
      } else {
        countSymbol[i] = countSymbol[i - 1];
      }
    }

    for (int i = 1; i < str.size() + 1; ++i) {
      auto lastSufficient = std::upper_bound(countSymbol.begin() + i, countSymbol.end(), countSymbol[i - 1] + k);
      if (max < std::distance(countSymbol.begin() + i, lastSufficient)) {
        max = std::distance(countSymbol.begin() + i, lastSufficient);
      }
    }
  }

  std::cout << max;
  return 0;
}