#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> pos[i];
  }
  std::sort(pos.begin(), pos.end());

  std::vector<int> dp(n + 1);
  dp[2] = pos[1] - pos[0];
  if (n > 2) {
    dp[3] = pos[2] - pos[0];
  }
  for (int i = 4; i < n + 1; ++i) {
    dp[i] = std::min(dp[i - 1], dp[i - 2]) + pos[i - 1] - pos[i - 2];
  }

  std::cout << dp[n];
  return 0;
}