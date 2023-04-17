#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  const int inf = n * 300 + 1;
  std::vector<int> costs(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> costs[i];
  }

  if (n == 0) {
    std::cout << 0 << "\n" << 0 << " " << 0;
    return 0;
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
  // base
  for (int j = 0; j < n + 1; ++j) {
    dp[0][j] = inf;
  }
  if (costs[0] > 100) {
    dp[1][0] = inf;
    dp[1][1] = costs[0];
  } else {
    dp[1][0] = costs[0];
    dp[1][1] = inf;
  }
  for (int j = 2; j < n + 1; ++j) {
    dp[1][j] = inf;
  }

  // dp
  for (int i = 2; i < n + 1; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      if (costs[i - 1] > 100) {
        if (j == n) {
          dp[i][j] = dp[i - 1][j - 1] + costs[i - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j + 1];
        } else {
          dp[i][j] = std::min(dp[i - 1][j - 1] + costs[i - 1], dp[i - 1][j + 1]);
        }
      } else {
        if (j == n) {
          dp[i][j] = dp[i - 1][j] + costs[i - 1];
        } else {
          dp[i][j] = std::min(dp[i - 1][j] + costs[i - 1], dp[i - 1][j + 1]);
        }
      }
    }
  }

  // find answer
  int min = dp[n][0];
  int amount_tickets = 0;
  for (int j = 0; j < n + 1; ++j) {
    if (min >= dp[n][j]) {
      min = dp[n][j];
      amount_tickets = j;
    }
  }

  std::cout << min << "\n";
  std::cout << amount_tickets << " ";

  int i = n;
  int j = amount_tickets;
  int count = 0;
  std::vector<int> way;
  while (i != 0) {
      if (j != n && dp[i][j] == dp[i - 1][j + 1]) {
        count++;
        way.push_back(i);
        j++;
      } else if (costs[i - 1] > 100) {
        j--;
      }
    i--;
  }

  std::reverse(way.begin(), way.end());
  std::cout << count << "\n";
  for (int k = 0; k < count; ++k) {
    std::cout << way[k] << " ";
  }
  return 0;
}