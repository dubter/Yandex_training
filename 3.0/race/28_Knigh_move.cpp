#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
  //base
  dp[1][1] = 1;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (j > 1) {
        dp[i][j] += dp[i - 1][j - 2];
      }
      if (i > 1) {
        dp[i][j] += dp[i - 2][j - 1];
      }
    }
  }

  std::cout << dp[n][m];
  return 0;
}