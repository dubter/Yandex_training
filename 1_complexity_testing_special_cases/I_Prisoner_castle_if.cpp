#include <iostream>

int main() {
  int a, b, c, d, e;
  std::cin >> a >> b >> c >> d >> e;
  std::cout << ((d >= a && e >= b) || (d >= b && e >= a) || (d >= a && e >= c) || (d >= b && e >= c) || (d >= c && e >= a) || (d >= c && e >= b) ? "YES" : "NO");
  return 0;
}