#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

int main() {
  std::unordered_set<int> set1, set2;
  std::string first_str, second_str;
  std::getline(std::cin, first_str);
  std::getline(std::cin, second_str);

  int num = 0;
  for (int i = 0; i < first_str.size(); ++i) {
    if (first_str[i] == ' ') {
      set1.insert(num);
      num = 0;
    } else if (i == first_str.size() - 1) {
      num = num * 10 + (first_str[i] - '0');
      set1.insert(num);
      num = 0;
    } else {
      num = num * 10 + (first_str[i] - '0');
    }
  }
  for (int i = 0; i < second_str.size(); ++i) {
    if (second_str[i] == ' ') {
      set2.insert(num);
      num = 0;
    } else if (i == second_str.size() - 1) {
      num = num * 10 + (second_str[i] - '0');
      set2.insert(num);
      num = 0;
    } else {
      num = num * 10 + (second_str[i] - '0');
    }
  }

  std::vector<int> v1, v2;
  for (auto i = set1.begin(); i != set1.end(); ++i) {
    v1.push_back(*i);
  }
  for (auto i = set2.begin(); i != set2.end(); ++i) {
    v2.push_back(*i);
  }

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::vector<int> intersection;
  std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(intersection));
  for (auto &elem : intersection) {
    std::cout << elem << " ";
  }
  return 0;
}