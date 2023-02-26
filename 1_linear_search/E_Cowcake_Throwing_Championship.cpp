#include <iostream>
#include <vector>

int main() {
  int amount_nums;
  std::cin >> amount_nums;
  std::vector<int> array(amount_nums);
  for (int i = 0; i < amount_nums; ++i) {
    std::cin >> array[i];
  }

  int max = array[0];
  for (int i = 0; i < amount_nums; ++i) {
    if (max < array[i]) {
      max = array[i];
    }
  }

  int winner_position;
  for (int i = 0; i < amount_nums; ++i) {
    if (array[i] == max) {
      winner_position = i;
      break;
    }
  }

  int max_vasilys_distance = 0;
  for (int i = 1; i < amount_nums - 1; ++i) {
    if (array[i] % 10 == 5 && winner_position < i && array[i + 1] < array[i] && max_vasilys_distance < array[i]) {
      max_vasilys_distance = array[i];
    }
  }

  int highest_place = 1;
  for (int i = 0; i < amount_nums; ++i) {
    if (array[i] > max_vasilys_distance) {
      highest_place++;
    }
  }
  if (max_vasilys_distance == 0) {
    std::cout << 0;
  } else {
    std::cout << highest_place;
  }
  return 0;
}