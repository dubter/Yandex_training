#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<std::string> set;
  std::string str;
  while(std::cin >> str) {
    set.insert(str);
  }
  std::cout << set.size();
  return 0;
}