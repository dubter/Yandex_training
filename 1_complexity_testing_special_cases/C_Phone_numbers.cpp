#include <iostream>

void to_good_number(std::string &str) {
  std::string new_str = "";
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '+' && str[i + 1] == '7') {
      ++i;
    } else if (str[i] != '-' && str[i] != '(' && str[i] != ')') {
      new_str += str[i];
    }
  }
  if (new_str.size() == 7) {
    str = "495" + new_str;
  } else if (new_str.size() == 11) {
    new_str.erase(0, 1);
    str = new_str;
  } else {
    str = new_str;
  }
}

int main() {
  std::string considered_number;
  std::string first, second, third;
  std::cin >> considered_number >> first >> second >> third;
  to_good_number(considered_number);
  to_good_number(first);
  to_good_number(second);
  to_good_number(third);
  std::cout << (considered_number == first ? "YES" : "NO") << "\n";
  std::cout << (considered_number == second ? "YES" : "NO") << "\n";
  std::cout << (considered_number == third ? "YES" : "NO") << "\n";
  return 0;
}