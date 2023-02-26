#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int num_anys_cubs, num_boras_cubs;
  std::cin >> num_anys_cubs >> num_boras_cubs;
  std::vector<int> anys_cubs(num_anys_cubs), boras_cubs(num_boras_cubs);
  for (int i = 0; i < num_anys_cubs; ++i) {
    std::cin >> anys_cubs[i];
  }
  for (int i = 0; i < num_boras_cubs; ++i) {
    std::cin >> boras_cubs[i];
  }

  std::sort(anys_cubs.begin(), anys_cubs.end());
  std::sort(boras_cubs.begin(), boras_cubs.end());

  std::vector<int> set;
  std::set_intersection(anys_cubs.begin(), anys_cubs.end(), boras_cubs.begin(), boras_cubs.end(), std::back_inserter(set));
  std::cout << set.size() << "\n";
  for (auto &elem : set) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
  set.clear();

  std::set_difference(anys_cubs.begin(), anys_cubs.end(), boras_cubs.begin(), boras_cubs.end(), std::back_inserter(set));
  std::cout << set.size() << "\n";
  for (auto &elem : set) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
  set.clear();

  std::set_difference(boras_cubs.begin(), boras_cubs.end(), anys_cubs.begin(), anys_cubs.end(), std::back_inserter(set));
  std::cout << set.size() << "\n";
  for (auto &elem : set) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
  set.clear();

  return 0;
}