#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  int num;
  int num_uniques = 0;
  std::unordered_map<int, int> dict;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    dict[num] += 1;

    if (dict[num] == 1) {
      num_uniques++;
    } else if (dict[num] == 2) {
      num_uniques--;
    }
  }

  std::cout << num_uniques;
  return 0;
}