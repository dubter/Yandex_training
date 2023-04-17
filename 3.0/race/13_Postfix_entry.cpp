#include <iostream>
#include <stack>

int main() {
  std::stack<int> stack;
  int last, pre_last;
  std::string str;
  while (std::cin >> str) {
    if (str == "+" || str == "-" || str == "*") {  // read sign
      last = stack.top();
      stack.pop();
      pre_last = stack.top();
      stack.pop();

      if (str == "+") {
        stack.push(pre_last + last);
      } else if (str == "-") {
        stack.push(pre_last - last);
      } else if (str == "*") {
        stack.push(pre_last * last);
      }
    } else {  // read number
      stack.push(std::stoi(str));
    }
  }

  std::cout << stack.top();
  return 0;
}