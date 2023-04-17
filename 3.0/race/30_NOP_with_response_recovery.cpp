#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n;
  std::vector<int> seq1(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> seq1[i];
  }
  std::cin >> m;
  std::vector<int> seq2(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> seq2[i];
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
  // base
  for (int i = 0; i < n + 1; ++i) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < m + 1; ++i) {
    dp[0][i] = 0;
  }

  // dp
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (seq1[i - 1] == seq2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // find seq
  int i = n;
  int j = m;
  std::vector<int> lcs;
  while (i > 0 && j > 0) {
    if (seq1[i - 1] == seq2[j - 1]) {
      lcs.push_back(seq1[i - 1]);
      i--;
      j--;
    } else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }

  std::reverse(lcs.begin(), lcs.end());
  for (size_t k = 0; k < lcs.size(); ++k) {
    std::cout << lcs[k] << " ";
  }
  return 0;
}