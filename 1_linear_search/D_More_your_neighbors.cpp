#include <iostream>
#include <vector>

int main() {
  int count_nums = 0;
  int curr_num;
  std::vector<int> array;
  while (std::cin >> curr_num) {
    array.push_back(curr_num);
  }
  for (int i = 1; i < array.size() - 1; ++i) {
    if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
      count_nums++;
    }
  }
  std::cout << count_nums;
  return 0;
}