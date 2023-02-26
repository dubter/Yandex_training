#include <iostream>

int main() {
  int n, k, row_num, place;
  std::cin >> n >> k >> row_num >> place;
  int petr_place = (row_num - 1) * 2 + place;
  int back_row = -1, front_row = -1, back_place, front_place;
  if (petr_place + k <= n) {
    if ((petr_place + k) % 2 == 0) {
      front_row = (petr_place + k) / 2;
      front_place = 2;
    } else {
      front_row = (petr_place + k) / 2 + 1;
      front_place = 1;
    }
  }

  if (petr_place - k >= 1) {
    if ((petr_place - k) % 2 == 0) {
      back_row = (petr_place - k) / 2;
      back_place = 2;
    } else {
      back_row = (petr_place - k) / 2 + 1;
      back_place = 1;
    }
  }

  if (front_row != -1 && back_row != -1 && row_num - back_row >= front_row - row_num) {
    std::cout << front_row << " " << front_place;
  } else if (front_row != -1 && back_row != -1) {
    std::cout << back_row << " " << back_place;
  } else if (front_row != -1) {
    std::cout << front_row << " " << front_place;
  } else if (back_row != -1) {
    std::cout << back_row << " " << back_place;
  } else {
    std::cout << -1;
  }
  return 0;
}