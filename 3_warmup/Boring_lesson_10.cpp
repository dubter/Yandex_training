#include <iostream>
#include <map>

int main() {
  std::map<char, size_t> map;
  std::string str;
  std::cin >> str;
  for (size_t i = 0; i < str.size(); ++i) {
    map[str[i]] += (i + 1) * static_cast<int>(str.size() - i);
  }

  for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << it->first << ": " << it->second << "\n";
  }
  return 0;
}