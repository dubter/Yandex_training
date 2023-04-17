#include <iostream>
#include <vector>

struct Node {
  int x;
  int y;
  int isValid = true;
};

int main() {
  int m , n;
  std::cin >> m >> n;
  int x , y;
  std::vector<Node> os;
  for (int i = 0; i < n; ++i) {
    std::cin >> x >> y;
    for (int j = 0; j < os.size(); ++j) {
      if (x <= os[j].y && y >= os[j].x) {
        os[j].isValid = false;
      }
    }

    os.push_back({x, y});
  }

  int count = 0;
  for (int i = 0; i < os.size(); ++i) {
    if (os[i].isValid) {
      count++;
    }
  }

  std::cout << count;
  return 0;
}