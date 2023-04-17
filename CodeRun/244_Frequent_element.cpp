#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  int num;
  int max_frequency = 0;
  int frequent_value = 0;
  std::unordered_map<int, int> dict;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    dict[num] += 1;
    if (max_frequency < dict[num]) {
      max_frequency = dict[num];
      frequent_value = num;
    } else if (max_frequency == dict[num]) {
      if (num > frequent_value) {
        frequent_value = num;
      }
    }
  }

  std::cout << frequent_value;
  return 0;
}