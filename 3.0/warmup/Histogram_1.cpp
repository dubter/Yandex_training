#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  std::string sub_str;
  std::string str;
  while(std::getline(std::cin, sub_str)) {
    str += sub_str;
  }
  std::map<int, int> map;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i]  != ' ' && str[i] != '\n') {
      map[str[i]] += 1;
    }
  }
  int max = 0;
  int count = 0;
  for (auto i = map.begin(); i != map.end(); ++i) {
    count++;
    if (max < i->second) {
      max = i->second;
    }
  }
  std::vector<std::vector<char>> matrix(max + 1, std::vector<char>(count, ' '));
  int j = 0;
  for (auto i = map.begin(); i != map.end(); ++i) {
    matrix[max][j] = i->first;
    j++;
  }
  int k = -1;
  for (auto i = map.begin(); i != map.end(); ++i) {
    k++;
    int amount = max - 1;
    while (i->second > 0) {
      matrix[amount][k] = '#';
      amount--;
      i->second -= 1;
    }
  }
  for (int i = 0; i < max + 1; ++i) {
    for (int j = 0; j < count; ++j) {
      std::cout << matrix[i][j];
    }
    std::cout << '\n';
  }
}
