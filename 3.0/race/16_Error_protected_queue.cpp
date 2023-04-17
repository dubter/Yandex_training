#include <iostream>
#include <queue>

int main() {
  std::string command;
  std::queue<int> queue;
  int num;
  while (command != "exit") {
    std::cin >> command;
    if (command == "push") {
      std::cin >> num;
      queue.push(num);
      std::cout << "ok" << "\n";
    } else if (command == "pop") {
      if (queue.empty()) {
        std::cout << "error" << "\n";
      } else {
        int front = queue.front();
        queue.pop();
        std::cout << front << "\n";
      }
    } else if (command == "front") {
      if (queue.empty()) {
        std::cout << "error" << "\n";
      } else {
        std::cout << queue.front() << "\n";
      }
    } else if (command == "size") {
      std::cout << queue.size() << "\n";
    } else if (command == "clear") {
      while(!queue.empty()) {
        queue.pop();
      }
      std::cout << "ok" << "\n";
    }
  }
  std::cout << "bye";
  return 0;
}
