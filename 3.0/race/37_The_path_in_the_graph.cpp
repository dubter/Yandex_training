#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph {
 public:
  explicit Graph(int size) : adj_(size), dist_(size, max_dist_), parents_(size, -1) {}

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
          parents_[neighbour] = front;
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

  std::vector<int> GetPath(int start, int end) {
    std::vector<int> path;
    int curr = end;
    while (curr != start) {
      path.push_back(curr);
      curr = parents_[curr];
    }
    path.push_back(curr);

    std::reverse(path.begin(), path.end());
    return std::move(path);
  }

 private:
  const int max_dist_ = 101;
  std::vector<std::vector<int>> adj_;
  std::vector<int> dist_;
  std::vector<int> parents_;
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

  if (graph.GetDistance(end) == -1) {
    std::cout << -1;
  } else if (graph.GetDistance(end) == 0) {
    std::cout << 0;
  } else {
    std::cout << graph.GetDistance(end) << "\n";
    std::vector<int> path = graph.GetPath(start, end);
    for (int i = 0; i < static_cast<int>(path.size()); ++i) {
      std::cout << ++path[i] << " ";
    }
  }
  return 0;
}