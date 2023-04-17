#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  std::vector<int> b(n + 1);
  std::vector<int> c(n + 1);

  for (int i = 1; i < n + 1; ++i) {
    std::cin >> a[i] >> b[i] >> c[i];
  }

  std::vector<int> dp(n + 1);
  dp[1] = a[1];
  dp[2] = std::min(dp[1] + a[2], b[1]);
  dp[3] = std::min(std::min(dp[2] + a[3], b[2] + a[1]), c[1]);
  for (int i = 4; i < n + 1; ++i) {
    dp[i] = std::min(std::min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]), dp[i - 3] + c[i - 2]);
  }

  std::cout << dp[n];
  return 0;
}