#include <iostream>
#include <vector>

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

  void DFS(int ver, int curr_comp) {
    colours_[ver] = GRAY;
    components_[curr_comp].push_back(ver);
    for (auto neighbour : adj_[ver]) {
      if (colours_[neighbour] == WHITE) {
        DFS(neighbour, curr_comp);
      }
    }
    colours_[ver] = BLACK;
  }

  std::vector<std::vector<int>> &FindConnectivities() {
    amount_comps_ = 0;
    for (size_t i = 0; i < adj_.size(); ++i) {
      if (colours_[i] == WHITE) {
        components_.resize(amount_comps_ + 1);
        DFS(static_cast<int>(i), amount_comps_);
        amount_comps_++;
      }
    }
    return components_;
  }

 private:
  int amount_comps_;
  std::vector<std::vector<int>> adj_;
  std::vector<int> colours_;
  std::vector<std::vector<int>> components_;
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

  std::vector<std::vector<int>> ans = graph.FindConnectivities();
  std::cout << ans.size() << "\n";
  for (size_t i = 0; i < ans.size(); ++i) {
    std::cout << ans[i].size() << "\n";
    for (size_t j = 0; j < ans[i].size(); ++j) {
      std::cout << ++ans[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}