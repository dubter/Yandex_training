#include <vector>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> amount_sequences(n + 1);
  amount_sequences[1] = 2;
  amount_sequences[2] = 4;
  amount_sequences[3] = 7;
  amount_sequences[4] = 13;


  for (int i = 5; i < n + 1; ++i) {
    amount_sequences[i] = 2 * amount_sequences[i - 1] - amount_sequences[i - 4];
  }

  std::cout << amount_sequences[n];
  return 0;
}