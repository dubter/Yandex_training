#include <iostream>
#include <vector>
#include <queue>

struct Coordinate {
  int z;
  int y;
  int x;
};

class Graph {
 public:
  Graph(int size, std::vector<std::vector<std::vector<char>>> &cube) : dist_(size, std::vector<std::vector<int>>(size, std::vector<int>(size, max_dist_))) {
    cube_ = cube;
  }

  void Bfs(int start_z, int start_y, int start_x) {
    std::vector<int> step_z{0, 0, 0, 0, 1, -1};
    std::vector<int> step_y{1, -1, 0, 0, 0, 0};
    std::vector<int> step_x{0, 0, 1, -1, 0, 0};

    dist_[start_z][start_y][start_x] = 0;
    std::queue<Coordinate> queue;
    queue.emplace(start_z, start_y, start_x);

    while (!queue.empty()) {
      Coordinate node = queue.front();
      queue.pop();
      for (int i = 0; i < step_z.size(); ++i) {
        if (step_z[i] + node.z >= 0 && step_z[i] + node.z < cube_.size()) {
          if (step_x[i] + node.x >= 0 && step_x[i] + node.x< cube_.size()) {
            if (step_y[i] + node.y >= 0 && step_y[i] + node.y < cube_.size()) {
              if (dist_[step_z[i] + node.z][step_y[i] + node.y][step_x[i] + node.x] == max_dist_ && cube_[step_z[i] + node.z][step_y[i] + node.y][step_x[i] + node.x] == '.') {
                dist_[step_z[i] + node.z][step_y[i] + node.y][step_x[i] + node.x] = dist_[node.z][node.y][node.x] + 1;
                queue.emplace(step_z[i] + node.z, step_y[i] + node.y, step_x[i] + node.x);
              }
            }
          }
        }
      }
    }
  }

  int GetDistance() {
    int min = max_dist_;
    for (int i = 0; i < cube_.size(); ++i) {
      for (int j = 0; j < cube_.size(); ++j) {
        if (dist_[0][i][j] < min) {
          min = dist_[0][i][j];
        }
      }
    }

    return min;
  }

 private:
  const int max_dist_ = 30 * 30 * 30 + 1;
  std::vector<std::vector<std::vector<int>>> dist_;
  std::vector<std::vector<std::vector<char>>> cube_;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::vector<char>>> cube(n, std::vector<std::vector<char>>(n, std::vector<char>(n)));
  int start_x, start_y, start_z;
  for (int z = 0; z < n; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        std::cin >> cube[z][y][x];

        if (cube[z][y][x] == 'S') {
          start_y = y;
          start_x = x;
          start_z = z;
        }
      }
    }
  }

  Graph graph(n, cube);
  graph.Bfs(start_z, start_y, start_x);

  std::cout << graph.GetDistance();
  return 0;
}