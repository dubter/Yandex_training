#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, INT32_MAX);
  std::vector<int> prev(n + 1);
  prev[1] = 0;
  dp[1] = 0;
  for (int i = 2; i < n + 1; ++i) {
    if (i % 3 == 0 && dp[i] > dp[i / 3]) {
      dp[i] = dp[i / 3];
      prev[i] = i / 3;
    }
    if (i % 2 == 0 && dp[i] > dp[i / 2]) {
      dp[i] = dp[i / 2];
      prev[i] = i / 2;
    }
    if (dp[i] > dp[i - 1]) {
      dp[i] = dp[i - 1];
      prev[i] = i - 1;
    }
    dp[i]++;
  }

  std::cout << dp[n] << "\n";

  int j = n;
  std::vector<int> way;
  while (prev[j] != 0) {
    way.push_back(j);
    j = prev[j];
  }
  way.push_back(1);

  for (int i = static_cast<int>(way.size() - 1); i >= 0; --i) {
    std::cout << way[i] << " ";
  }
  return 0;
}