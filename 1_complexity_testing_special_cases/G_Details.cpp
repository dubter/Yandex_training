#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, k, m;
  std::cin >> n >> k >> m;
  int remains = n;
  int count_details = 0;
  while (remains >= k) {
    int count_blanks = remains / k;
    remains = remains % k;
    if (k / m == 0) {
      break;
    }
    count_details += count_blanks * (k / m);
    remains += count_blanks * (k % m);
  }
  std::cout << count_details;
  return 0;
}