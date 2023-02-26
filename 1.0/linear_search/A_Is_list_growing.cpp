#include <iostream>

int main() {
  int curr, last;
  int i = 0;
  bool is_growing = true;
  while (std::cin >> curr) {
    if (i != 0 && curr <= last) {
      is_growing = false;
    }
    i++;
    last = curr;
  }
  if (is_growing) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}