#include <iostream>
#include <stack>

int main() {
  int n;
  std::cin >> n;

  std::stack<int> stack;
  int num;
  int amount_wagons_in_way2 = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    stack.push(num);
    while (!stack.empty() && stack.top() == amount_wagons_in_way2 + 1) {
      amount_wagons_in_way2++;
      stack.pop();
    }
  }

  if (stack.empty()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}