#include <iostream>
#include <queue>

int main() {
  const int start_amount = 5;
  const int max_amount_moves = 1000000;
  std::queue<int> player1;
  std::queue<int> player2;

  int num;
  for (int i = 0; i < start_amount; ++i) {
    std::cin >> num;
    player1.push(num);
  }

  for (int i = 0; i < start_amount; ++i) {
    std::cin >> num;
    player2.push(num);
  }

  int amount_moves = 0;
  while (amount_moves <= max_amount_moves && !player2.empty() && !player1.empty()) {
    amount_moves++;
    int front1 = player1.front();
    int front2 = player2.front();

    player1.pop();
    player2.pop();

    if (front1 == 0 && front2 == 9) {
      player1.push(front1);
      player1.push(front2);
      continue;
    }

    if (front2 == 0 && front1 == 9) {
      player2.push(front1);
      player2.push(front2);
      continue;
    }

    if (front1 > front2) {
      player1.push(front1);
      player1.push(front2);
    } else {
      player2.push(front1);
      player2.push(front2);
    }
  }

  if (amount_moves > max_amount_moves) {
    std::cout << "botva";
  } else if (player1.empty()) {
    std::cout << "second " << amount_moves;
  } else {
    std::cout << "first " << amount_moves;
  }
  return 0;
}