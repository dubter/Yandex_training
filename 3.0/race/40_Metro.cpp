#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Graph {
 public:
  Graph(int size, std::vector<std::vector<int>> &lines) {
    lines_ = lines;
    dist_.resize(lines.size(), max_dist_);

    for (int i = 0; i < lines.size(); ++i) {
      for (int j = 0; j < lines[i].size(); ++j) {
        from_ver_to_line_[lines[i][j]].push_back(i);
      }
    }
  }

  void Bfs(int start) {
    // queue for lines
    std::queue<int> queue;

    for (auto line : from_ver_to_line_[start]) {
      queue.push(line);
      dist_[line] = 0;
    }

    while (!queue.empty()) {
      int line = queue.front();
      queue.pop();

      for (auto ver : lines_[line]) {
        if (from_ver_to_line_[ver].size() > 1) {
          for (int neighbour_line : from_ver_to_line_[ver]) {
            if (dist_[neighbour_line] == max_dist_) {
              dist_[neighbour_line] = dist_[line] + 1;
              queue.push(neighbour_line);
            }
          }
        }
      }
    }
  }

  int GetDistance(int end) {
    int min = max_dist_;
    for (auto line : from_ver_to_line_[end]) {
      if (min > dist_[line]) {
        min = dist_[line];
      }
    }
    if (min == max_dist_) {
      return -1;
    }
    return min;
  }

 private:
  const int max_dist_ = 101;
  std::vector<std::vector<int>> lines_;
  std::map<int, std::vector<int>> from_ver_to_line_;
  std::vector<int> dist_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  int amount_vers_in_line;
  int ver;
  std::vector<std::vector<int>> lines(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> amount_vers_in_line;
    for (int j = 0; j < amount_vers_in_line; ++j) {
      std::cin >> ver;
      lines[i].push_back(--ver);
    }
  }

  int start, end;
  std::cin >> start >> end;
  --start;
  --end;

  Graph graph(n, lines);
  graph.Bfs(start);

  std::cout << graph.GetDistance(end);
  return 0;
}