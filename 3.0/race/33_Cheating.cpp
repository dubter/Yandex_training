#include <iostream>
#include <vector>

enum COLOUR {
  GREEN,
  RED,
  WHITE,
};

class Graph {
 public:
  explicit Graph(int size) {
    adj_.resize(size);
    colours_.resize(size, WHITE);
    can_divided_ = true;
  }

  void AddEdge(int ver1, int ver2) {
    adj_[ver1].push_back(ver2);
    adj_[ver2].push_back(ver1);
  }

  void DFS(int ver, int cur_colour) {
    colours_[ver] = cur_colour;

    // check current vertex
    for (auto neighbour : adj_[ver]) {
      if (colours_[neighbour] == cur_colour) {
        can_divided_ = false;
      }
    }

    // dfs
    for (auto neighbour : adj_[ver]) {
      if (colours_[neighbour] == WHITE) {
        DFS(neighbour, 1 - cur_colour);
      }
    }
  }

  void IsAbleTwoTones() {
    for (int i = 0; i < static_cast<int>(adj_.size()) && can_divided_; ++i) {
      if (colours_[i] == WHITE) {
        DFS(i, GREEN);
      }
    }
  }

  bool GetAnswer() const {
    return can_divided_;
  }

 private:
  std::vector<std::vector<int>> adj_;
  std::vector<int> colours_;
  bool can_divided_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph graph(n);
  int ver1, ver2;
  for (int i = 0; i < m; ++i) {
    std::cin >> ver1 >> ver2;
    graph.AddEdge(--ver1, --ver2);
  }

  graph.IsAbleTwoTones();
  if (graph.GetAnswer()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}