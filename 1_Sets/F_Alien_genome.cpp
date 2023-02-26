#include <iostream>
#include <unordered_set>

int main() {
  std::string str1, str2;
  std::cin >> str1 >> str2;

  std::unordered_set<std::string> pairs;
  for (int i = 0; i < str2.size() - 1; ++i) {
    std::string tmp;
    tmp += str2[i];
    tmp += str2[i + 1];
    pairs.insert(tmp);
  }

  int count = 0;
  for (int i = 0; i < str1.size() - 1; ++i) {
    std::string tmp;
    tmp += str1[i];
    tmp += str1[i + 1];
    if (pairs.find(tmp) != pairs.end()) {
      count++;
    }
  }
  std::cout << count;
  return 0;
}