#include <iostream>
#include <stack>

int main() {
  std::string bracket_sequence;
  std::cin >> bracket_sequence;

  std::stack<char> stack;
  bool is_correct = true;
  for (int i = 0; i < bracket_sequence.size(); ++i) {
    if (!stack.empty()) {
      if (bracket_sequence[i] == ')' && stack.top() != '(') {
        is_correct = false;
        break;
      }
      if (bracket_sequence[i] == ']' && stack.top() != '[') {
        is_correct = false;
        break;
      }
      if (bracket_sequence[i] == '}' && stack.top() != '{') {
        is_correct = false;
        break;
      }
    }

    if (bracket_sequence[i] == '(' || bracket_sequence[i] == '{' || bracket_sequence[i] == '[') {
      stack.push(bracket_sequence[i]);
    } else if (stack.empty()) {
      is_correct = false;
      break;
    } else {
      stack.pop();
    }
  }

  if (is_correct && stack.empty()) {
    std::cout << "yes";
  } else {
    std::cout << "no";
  }
  return 0;
}