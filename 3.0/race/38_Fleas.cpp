#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  Graph(int n, int m) {
    dist_.resize(n, std::vector<int>(m, max_dist_));
    dim_n_ = n;
    dim_m_ = m;
  }

  void Bfs(int start_y, int start_x) {
    dist_[start_y][start_x] = 0;

    std::vector<int> steps_y{2, 2, -2, -2, 1, 1, -1, -1};
    std::vector<int> steps_x{1, -1, -1, 1, 2, -2, 2, -2};

    std::queue<std::pair<int, int>> queue;
    queue.emplace(start_y, start_x);
    while (!queue.empty()) {
      std::pair<int, int> front = queue.front();
      queue.pop();
      for (int i = 0; i < static_cast<int>(steps_y.size()); ++i) {
        if (front.first + steps_y[i] < dim_n_ && front.first + steps_y[i] >= 0 && front.second + steps_x[i] < dim_m_ && front.second + steps_x[i] >= 0) {
          if (dist_[front.first + steps_y[i]][front.second + steps_x[i]] == max_dist_) {
            dist_[front.first + steps_y[i]][front.second + steps_x[i]] = dist_[front.first][front.second] + 1;
            queue.emplace(front.first + steps_y[i], front.second + steps_x[i]);
          }
        }
      }
    }
  }

  int GetDistance(int end_y, int end_x) const {
    if (dist_[end_y][end_x] == max_dist_) {
      return -1;
    }
    return dist_[end_y][end_x];
  };

 private:
  const int max_dist_ = 250 * 250 + 1;
  int dim_n_;
  int dim_m_;
  std::vector<std::vector<int>> dist_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  int x_finish, y_finish;
  std::cin >> y_finish >> x_finish;
  x_finish--;
  y_finish--;
  int num_fleas;
  std::cin >> num_fleas;

  bool is_possible = true;
  int64_t sum = 0;
  int x_start, y_start;
  Graph graph(n, m);
  graph.Bfs(y_finish, x_finish);

  for (int i = 0; i < num_fleas; ++i) {
    std::cin >> y_start >> x_start;
    x_start--;
    y_start--;

    int num_steps = graph.GetDistance(y_start, x_start);
    if (num_steps == -1) {
      is_possible = false;
      break;
    } else {
      sum += num_steps;
    }
  }

  if (is_possible) {
    std::cout << sum;
  } else {
    std::cout << -1;
  }
  return 0;
}