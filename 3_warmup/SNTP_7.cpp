#include <iostream>
#include <vector>

int main() {
  std::string a, b, c;
  std::cin >> a >> b >> c;

  std::vector<int> A(3), B(3), C(3);
  for (int i = 0, j = 0; i < 3; ++i, j += 3) {
    A[i] = (a[j] - '0') * 10 + a[j + 1] - '0';
    B[i] = (b[j] - '0') * 10 + b[j + 1] - '0';
    C[i] = (c[j] - '0') * 10 + c[j + 1] - '0';
  }

  int diff;
  int c_sec = C[0] * 60 * 60 + C[1] * 60 + C[2];
  int a_sec = A[0] * 60 * 60 + A[1] * 60 + A[2];
  if (c_sec > a_sec) {
    diff = c_sec - a_sec;
  } else {
    diff = 24 * 60 * 60 + c_sec - a_sec;
  }
  if (diff % 2 != 0) {
    diff++;
  }
  diff /= 2;

  int hours = diff / (60 * 60);
  diff %= 60 * 60;
  int minutes = diff / 60;
  diff %= 60;
  int sec = diff;

  hours = (B[0] + hours) % 24 + (B[1] + minutes) / 60;
  minutes = (B[1] + minutes) % 60 + (B[2] + sec) / 60;
  sec = (B[2] + sec) % 60;

  if (hours / 10 == 0) {
    std::cout << "0" << hours << ":";
  } else {
    std::cout << hours << ":";
  }
  if (minutes / 10 == 0) {
    std::cout << "0" << minutes << ":";
  } else {
    std::cout << minutes << ":";
  }
  if (sec / 10 == 0) {
    std::cout << "0" << sec;
  } else {
    std::cout << sec;
  }
  return 0;
}