#include <iostream>
#include <vector>
#include <algorithm>

class Node {
 public:
  int num;
  int rate;
  int index;
};

int main() {
  int m , n;
  std::cin >> m >> n;
  std::vector<Node> all_nums(2 * n);
  int x , y;
  for (int i = 0; i < 2 * n; i += 2) {
    std::cin >> x >> y;
    all_nums[i] = {x, -1, i / 2};
    all_nums[i + 1] = {y, 1, (i + 1) / 2};
  }

  std::sort(all_nums.begin(), all_nums.end(), [](const Node &node1, const Node &node2) {
    return (node1.num < node2.num) || ((node1.num == node2.num) && (node1.rate < node2.rate)) || ((node1.num == node2.num) && (node1.rate == node2.rate) && (node1.index > node2.index));
  });

  int curr_section = -1;
  int count = 0;
  for (auto node : all_nums) {
    if (curr_section != -1) {
      if (node.index == curr_section) {
        count++;
        curr_section = -1;
      } else {
        if (curr_section < node.index) {
          curr_section = node.index;
        }
      }
    } else if (node.rate == -1) {
      curr_section = node.index;
    }
  }
  std::cout << count;
  return 0;
}