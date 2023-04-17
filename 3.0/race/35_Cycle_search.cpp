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
    colour_.resize(size, WHITE);
    has_cycle = false;
  }

  void AddEdge(int ver1, int ver2) {
    adj_[ver1].push_back(ver2);
    adj_[ver2].push_back(ver1);
  }

  void DfsVisit(int ver, int parent) {
    colour_[ver] = GRAY;
    way_.push_back(ver);
    for (auto neighbour : adj_[ver]) {
      if (has_cycle) {
        return;
      }

      if (neighbour == parent) {
        continue;
      }

      if (colour_[neighbour] == GRAY) {
        way_.push_back(neighbour);
        has_cycle = true;
        return;
      } else if (colour_[neighbour] == WHITE) {
        DfsVisit(neighbour, ver);
      }
    }
    colour_[ver] = BLACK;
    way_.pop_back();
  }

  bool HasCycle() {
    for (int i = 0; i < static_cast<int>(adj_.size()) && !has_cycle; ++i) {
      if (colour_[i] == WHITE) {
        DfsVisit(i, -1);

        if (has_cycle) {
          break;
        }
      }
    }

    return has_cycle;
  }

  std::vector<int> CycleWay() {
    std::vector<int> cycle;
    int start = way_.back();
    int i = way_.size() - 2;
    int curr = way_[i];
    while (curr != start) {
      cycle.push_back(curr);
      i--;
      curr = way_[i];
    }
    cycle.push_back(curr);

    return cycle;
  }

 private:
  bool has_cycle;
  std::vector<std::vector<int>> adj_;
  std::vector<int> colour_;
  std::vector<int> way_;
};

int main() {
  int n;
  std::cin >> n;
  int has_edge;
  Graph graph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> has_edge;

      if (has_edge == 1) {
        graph.AddEdge(i, j);
      }
    }
  }

  if (graph.HasCycle()) {
    std::cout << "YES" << "\n";
    std::vector<int> cycle = graph.CycleWay();
    std::cout << cycle.size() << "\n";
    for (int i = 0; i < static_cast<int>(cycle.size()); ++i) {
      std::cout << ++cycle[i] << " ";
    }
  } else {
    std::cout << "NO";
  }

  return 0;
}