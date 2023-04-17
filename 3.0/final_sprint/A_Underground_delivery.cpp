#include <map>
#include <iostream>
#include <stack>

struct Node {
  std::string name;
  int amount_wagons;
};

int main() {
  int n;
  std::cin >> n;
  std::stack<Node> stack;
  std::map<std::string, int64_t> num_products;
  std::string mode;
  int num;
  std::string name;
  for (int i = 0; i < n; ++i) {
    std::cin >> mode;

    if (mode == "add") {
      std::cin >> num >> name;

      num_products[name] += num;
      stack.push({name, num});
    } else if (mode == "get") {
      std::cin >> name;

      std::cout << num_products[name] << "\n";
    } else if (mode == "delete") {
      std::cin >> num;

      while (num > 0) {
        Node top = stack.top();
        stack.pop();
        if (top.amount_wagons > num) {
          stack.push({top.name, top.amount_wagons - num});
          num_products[top.name] -= num;
        } else {
          num_products[top.name] -= top.amount_wagons;
        }
        num -= top.amount_wagons;
      }
    }
  }
  return 0;
}