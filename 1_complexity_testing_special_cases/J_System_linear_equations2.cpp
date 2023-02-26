#include <iostream>

int main() {
  double a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
    std::cout << 5;
  } else if (a == 0 && b == 0 && c == 0 && d == 0 && (e != 0 || f != 0)) {
    std::cout << 0;
  } else if (b == 0 && d == 0 && a * f == e * c) {
    if (a == 0) {
      std::cout << 3 << " " << f / c;
    } else {
      std::cout << 3 << " " << e / a;
    }
  } else if (a == 0 && c == 0 && b * f == d * e) {
    if (b == 0) {
      std::cout << 4 << " " << f / d;
    } else {
      std::cout << 4 << " " << e / b;
    }
  } else if (a == 0 && b == 0 && e == 0) {
    std::cout << 1 << " " << -c / d << " " << f / d;
  } else if (c == 0 && d == 0 && f == 0) {
    std::cout << 1 << " " << -a / b << " " << e / b;
  } else if (b != 0 && a * d == c * b && b * f == d * e) {
    std::cout << 1 << " " << -a / b << " " << e / b;
  } else if (a * d == c * b) {
    std::cout << 0;
  } else {
    if (b * f == d * e) {
      std::cout << 2 << " " << 0 << " ";
    } else {
      std::cout << 2 << " " << (b * f - d * e) / (b * c - d * a) << " ";
    }
    if (a * f == c * e) {
      std::cout << 0;
    } else {
      std::cout << (a * f - c * e) / (a * d - c * b);
    }
  }
  return 0;
}