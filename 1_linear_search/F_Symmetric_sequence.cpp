#include <iostream>
#include <vector>

int main() {
  int amount_nums;
  std::cin >> amount_nums;
  std::vector<int> sequence(amount_nums);
  for (int i = 0; i < amount_nums; ++i) {
    std::cin >> sequence[i];
  }
  int i = amount_nums - 1;
  int symmetric_index = i;
  for (; i >= 0; --i) {
    int first = i;
    int second = amount_nums - 1;
    while (first < second && sequence[first] == sequence[second]) {
      first++;
      second--;
    }
    if (second <= first) {
      symmetric_index = i;
    }
  }
  std::cout << symmetric_index << "\n";
  for (int j = symmetric_index - 1; j >= 0; --j) {
    std::cout << sequence[j] << " ";
  }
  return 0;
}