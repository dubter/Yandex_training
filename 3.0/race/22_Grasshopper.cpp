#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> amount_ways(n + 1, 0);

  int sum = 1;
  amount_ways[1] = 1;
  for (int i = 2; i < k + 1 && i < n + 1; ++i) {
    amount_ways[i] = sum;
    sum += amount_ways[i];
  }

  for (int i = k + 1; i < n + 1; ++i) {
    for (int j = i - 1; j >= i - k; --j) {
      amount_ways[i] += amount_ways[j];
    }
  }

  std::cout << amount_ways[n];
  return 0;
}