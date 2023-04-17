#include <iostream>
#include <unordered_set>

int main() {
  std::string a;
  std::string b;
  std::cin >> a >> b;

  std::unordered_set<char> set;
  for (int i = 0; i < a.size(); ++i) {
    set.insert(a[i]);
  }

  int count = 0;
  for (int i = 0; i < b.size(); ++i) {
    if (set.find(b[i]) != set.end()) {
      count++;
    }
  }

  std::cout << count;
  return 0;
}