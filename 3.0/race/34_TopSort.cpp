#include <iostream>
#include <vector>
#include <algorithm>

enum {
  WHITE,
  GRAY,
  BLACK,
};

class Graph {
 public:
  explicit Graph(int size) {
    adj_.resize(size);
    colours_.resize(size, WHITE);
    has_cycle = false;
  }

  void AddEdge(int ver1, int ver2) {
    adj_[ver1].push_back(ver2);
  }

  void DFSVisit(int ver) {
    colours_[ver] = GRAY;
    for (auto neighbour : adj_[ver]) {
      if (colours_[neighbour] == GRAY) {
        has_cycle = true;
      } else if (colours_[neighbour] == WHITE) {
        DFSVisit(neighbour);
      }
    }
    colours_[ver] = BLACK;
    sorted_graph.push_back(ver);
  }

  void DFS() {
    for (int i = 0; i < static_cast<int>(adj_.size()); ++i) {
      if (colours_[i] == WHITE) {
        DFSVisit(i);

        if (has_cycle) {
          break;
        }
      }
    }
  }

  bool hasCycle() const {
    return has_cycle;
  }

  std::vector<int> &TopSort() {
    std::reverse(sorted_graph.begin(), sorted_graph.end());
    return sorted_graph;
  }

 private:
  std::vector<std::vector<int>> adj_;
  std::vector<int> sorted_graph;
  std::vector<int> colours_;
  bool has_cycle;
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
  graph.DFS();

  if (!graph.hasCycle()) {
    std::vector<int> ans = graph.TopSort();
    for (size_t i = 0; i < ans.size(); ++i) {
      std::cout << ++ans[i] << " ";
    }
  } else {
    std::cout << -1;
  }
  return 0;
}