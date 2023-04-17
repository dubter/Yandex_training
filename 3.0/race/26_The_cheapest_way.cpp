#include <iostream>
#include <vector>

int main() {
  const int inf = 20 * 100 + 1;
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> field(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> field[i][j];
    }
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
  // base
  for (int j = 0; j < m + 1; ++j) {
    dp[0][j] = inf;
  }
  for (int i = 0; i < n + 1; ++i) {
    dp[i][0] = inf;
  }
  dp[1][1] = field[0][0];

  //dp
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (i == 1 && j == 1) {
        continue;
      }

      dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + field[i - 1][j - 1];
    }
  }

  std::cout << dp[n][m];
  return 0;
}