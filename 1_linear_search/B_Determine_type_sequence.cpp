#include <iostream>
#include <vector>

enum type_sequence {
  CONSTANT,
  ASCENDING,
  WEAKLY_ASCENDING,
  DESCENDING,
  WEAKLY_DESCENDING
};

int main() {
  std::vector<bool> types(6, true);
  const int end = -2000000000;
  int curr = 0, last = 0;
  int i = 0;
  std::cin >> curr;
  while (curr != end) {
    if (i != 0) {
      if (curr != last) {
        types[CONSTANT] = false;
      }
      if (curr < last) {
        types[WEAKLY_ASCENDING] = false;
      }
      if (curr > last) {
        types[WEAKLY_DESCENDING] = false;
      }
      if (curr <= last) {
        types[ASCENDING] = false;
      }
      if (curr >= last) {
        types[DESCENDING] = false;
      }
    }
    ++i;
    last = curr;
    std::cin >> curr;
  }
  for (int i = 0; i < 7; ++i) {
    if (types[i]) {
      if (i == CONSTANT) {
        std::cout << "CONSTANT";
      } else if (i == ASCENDING) {
        std::cout << "ASCENDING";
      } else if (i == WEAKLY_ASCENDING) {
        std::cout << "WEAKLY ASCENDING";
      } else if (i == DESCENDING) {
        std::cout << "DESCENDING";
      } else if (i == WEAKLY_DESCENDING) {
        std::cout << "WEAKLY DESCENDING";
      } else {
        std::cout << "RANDOM";
      }
      break;
    }
  }
  return 0;
}