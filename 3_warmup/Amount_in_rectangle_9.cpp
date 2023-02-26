#include <iostream>
#include <vector>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  std::vector<std::vector<int>> prefix_sum = matrix;
  for (int i = 1; i <= n; ++i) {
    prefix_sum[i][1] += prefix_sum[i - 1][1];
  }
  for (int j = 1; j <= m; ++j) {
    prefix_sum[1][j] += prefix_sum[1][j - 1];
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
    }
  }

  int x1, x2, y1, y2;
  for (int i = 0; i < k; ++i) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1] << "\n";
  }
  return 0;
}