#include <iostream>
#include <stack>

int main() {
  std::stack<int> stack;
  std::string command;
  int num;
  while (command != "exit") {
    std::cin >> command;
    if (command == "push") {
      std::cin >> num;
      stack.push(num);
      std::cout << "ok" << "\n";
    } else if (command == "pop") {
      if (stack.empty()) {
        std::cout << "error" << "\n";
      } else {
        int back = stack.top();
        stack.pop();
        std::cout << back << "\n";
      }
    } else if (command == "size") {
      std::cout << stack.size() << "\n";
    } else if (command == "clear") {
      while (!stack.empty()) {
        stack.pop();
      }
      std::cout << "ok" << "\n";
    } else if (command == "back") {
      if (stack.empty()) {
        std::cout << "error" << "\n";
      } else {
        std::cout << stack.top() << "\n";
      }
    }
  }
  std::cout << "bye";
  return 0;
}