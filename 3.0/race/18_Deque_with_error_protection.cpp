#include <iostream>
#include <deque>

int main() {
  std::string command;
  std::deque<int> deque;
  int num;
  while (command != "exit") {
    std::cin >> command;
    if (command == "push_front") {
      std::cin >> num;
      deque.push_front(num);
      std::cout << "ok" << "\n";
    } else if (command == "push_back") {
      std::cin >> num;
      deque.push_back(num);
      std::cout << "ok" << "\n";
    } else if (command == "pop_front") {
      if (deque.empty()) {
        std::cout << "error" << "\n";
      } else {
        int front = deque.front();
        deque.pop_front();
        std::cout << front << "\n";
      }
    } else if (command == "pop_back") {
      if (deque.empty()) {
        std::cout << "error" << "\n";
      } else {
        int back = deque.back();
        deque.pop_back();
        std::cout << back << "\n";
      }
    } else if (command == "front") {
      if (deque.empty()) {
        std::cout << "error" << "\n";
      } else {
        std::cout << deque.front() << "\n";
      }
    } else if (command == "back") {
      if (deque.empty()) {
        std::cout << "error" << "\n";
      } else {
        std::cout << deque.back() << "\n";
      }
    } else if (command == "size") {
      std::cout << deque.size() << "\n";
    } else if (command == "clear") {
      while(!deque.empty()) {
        deque.pop_front();
      }
      std::cout << "ok" << "\n";
    }
  }
  std::cout << "bye";
  return 0;
}
