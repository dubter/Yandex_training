#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  explicit Graph(int size) : adj_(size), dist_(size, max_dist_) {}

  void AddEdge(int ver1, int ver2) {
    adj_[ver2].push_back(ver1);
    adj_[ver1].push_back(ver2);
  }

  void Bfs(int start) {
    dist_[start] = 0;
    std::queue<int> queue;
    queue.push(start);
    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();
      for (auto neighbour : adj_[front]) {
        if (dist_[neighbour] == max_dist_) {
          dist_[neighbour] = dist_[front] + 1;
          queue.push(neighbour);
        }
      }
    }
  }

  int GetDistance(int end) {
    if (dist_[end] == max_dist_) {
      return -1;
    }
    return dist_[end];
  }

 private:
  const int max_dist_ = 101;
  std::vector<std::vector<int>> adj_;
  std::vector<int> dist_;
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

  int start, end;
  std::cin >> start >> end;
  --start;
  --end;
  graph.Bfs(start);

  std::cout << graph.GetDistance(end);
  return 0;
}