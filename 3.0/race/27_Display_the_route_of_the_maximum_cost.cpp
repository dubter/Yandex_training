#include <iostream>
#include <vector>
#include <algorithm>

int main() {
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
  for (int i = 0; i < n + 1; ++i) {
    dp[i][0] = 0;
  }
  for (int j = 0; j < m + 1; ++j) {
    dp[0][j] = 0;
  }

  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + field[i - 1][j - 1];
    }
  }

  std::cout << dp[n][m] << "\n";

  std::vector<char> way;
  int i = n;
  int j = m;
  while (i != 1 || j != 1) {
    if (dp[i][j] - field[i - 1][j - 1] == dp[i - 1][j]) {
      way.push_back('D');
      i--;
    } else {
      way.push_back('R');
      j--;
    }
  }
  std::reverse(way.begin(), way.end());

  for (size_t k = 0; k < way.size(); ++k) {
    std::cout << way[k] << " ";
  }
  return 0;
}