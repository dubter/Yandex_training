#include <iostream>
#include <vector>

int main() {
  int min_distance;
  int count_nums;
  int current_num;
  std::cin >> count_nums;
  std::vector<int> array(count_nums);
  for (int i = 0; i < count_nums; ++i) {
    std::cin >> array[i];
  }
  std::cin >> current_num;
  int nearest_num = array[0];
  min_distance = std::abs(array[0] - current_num);
  for (int i = 0; i < count_nums; ++i) {
    if (min_distance > std::abs(current_num - array[i])) {
      min_distance = std::abs(current_num - array[i]);
      nearest_num = array[i];
    }
  }
  std::cout << nearest_num;
  return 0;
}