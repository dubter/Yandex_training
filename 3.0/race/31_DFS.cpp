#include <iostream>
#include <vector>
#include <algorithm>

enum COLOUR {
  WHITE,
  GRAY,
  BLACK,
};

class Graph {
 public:
  explicit Graph(int size) {
    adj_.resize(size);
    colours_.resize(size, WHITE);
  }

  void AddEdge(int ver1, int ver2) {
    adj_[ver1].push_back(ver2);
    adj_[ver2].push_back(ver1);
  }

  void DFS(int ver) {
    colours_[ver] = GRAY;
    component_.push_back(ver);
    for (auto neighbour : adj_[ver]) {
      if (colours_[neighbour] == WHITE) {
        DFS(neighbour);
      }
    }
    colours_[ver] = BLACK;
  }

  std::vector<int> &FindConnectivity(int ver) {
    DFS(ver);
    std::sort(component_.begin(), component_.end());
    return component_;
  }

 private:
  std::vector<std::vector<int>> adj_;
  std::vector<int> colours_;
  std::vector<int> component_;
};

int main() {
  const int vertex = 0;
  int n, m;
  std::cin >> n >> m;
  Graph graph(n);
  int ver1, ver2;
  for (int i = 0; i < m; ++i) {
    std::cin >> ver1 >> ver2;
    graph.AddEdge(--ver1, --ver2);
  }

  std::vector<int> ans = graph.FindConnectivity(vertex);
  std::cout << ans.size() << "\n";
  for (size_t i = 0; i < ans.size(); ++i) {
    std::cout << ++ans[i] << " ";
  }
  return 0;
}