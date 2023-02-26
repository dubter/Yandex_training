#include <iostream>
#include <unordered_set>
#include <algorithm>

int main() {
  std::unordered_set<int> nums;
  int num;
  while(std::cin >> num) {
    nums.insert(num);
  }
  std::cout << nums.size();
  return 0;
}