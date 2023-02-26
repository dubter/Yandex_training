#include <iostream>
#include <vector>

int main() {
  int amount_rows, amount_columns;
  int amount_mines;
  std::cin >> amount_rows >> amount_columns >> amount_mines;
  std::vector<std::pair<int, int>> mines(amount_mines);
  for (int i = 0; i < amount_mines; ++i) {
    std::cin >> mines[i].first >> mines[i].second;
  }

  std::vector<std::vector<int>> game_field(amount_rows + 2, std::vector<int>(amount_columns + 2, 0));
  for (int i = 0; i < amount_mines; ++i) {
    game_field[mines[i].first][mines[i].second] = -9;

    game_field[mines[i].first - 1][mines[i].second - 1] += 1;
    game_field[mines[i].first + 1][mines[i].second + 1] += 1;
    game_field[mines[i].first + 1][mines[i].second - 1] += 1;
    game_field[mines[i].first - 1][mines[i].second + 1] += 1;
    game_field[mines[i].first][mines[i].second - 1] += 1;
    game_field[mines[i].first - 1][mines[i].second] += 1;
    game_field[mines[i].first + 1][mines[i].second] += 1;
    game_field[mines[i].first][mines[i].second + 1] += 1;
  }

  for (int i = 1; i <= amount_rows; ++i) {
    for (int j = 1; j <= amount_columns; ++j) {
      if (game_field[i][j] < 0) {
        std::cout << "* ";
      } else {
        std::cout << game_field[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
  return 0;
}