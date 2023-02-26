#include <iostream>
#include <vector>

std::vector<int> ZFunction(const std::vector<int> &sequence) {
  int left = 0;
  int right = 0;
  std::vector<int> z_arr;
  z_arr.resize(sequence.size(), 0);
  z_arr[0] = static_cast<int>(sequence.size());
  for (int i = 1; i < static_cast<int>(sequence.size()); ++i) {
    if (i < right) {
      z_arr[i] = std::min(z_arr[i - left], right - i);
    }
    while (i + z_arr[i] < static_cast<int>(sequence.size()) && sequence[z_arr[i]] == sequence[i + z_arr[i]]) {
      ++z_arr[i];
    }
    if (right < i + z_arr[i]) {
      left = i;
      right = i + z_arr[i];
    }
  }
  return z_arr;
}

int main() {
  int amount_elems;
  std::cin >> amount_elems;
  std::vector<int> sequence(amount_elems);
  for (int i = 0; i < amount_elems; ++i) {
    std::cin >> sequence[i];
  }

  std::vector<int> reversed_sequence = sequence;
  //  reverse sequense
  for (int i = 0; i < sequence.size() / 2; ++i) {
    std::swap(reversed_sequence[i], reversed_sequence[reversed_sequence.size() - i - 1]);
  }

  std::vector<int> new_sequence(2 * sequence.size());
  for (int i = 0; i < sequence.size(); ++i) {
    new_sequence[i] = reversed_sequence[i];
  }
  for (int i = 0; i < sequence.size(); ++i) {
    new_sequence[i + sequence.size()] = sequence[i];
  }

  std::vector<int> z_arr = ZFunction(new_sequence);
  int max = 0;
  for (int i = sequence.size(); i < z_arr.size(); ++i) {
    if (max < z_arr[i] && z_arr[i] + i == z_arr.size()) {
      max = z_arr[i];
    }
  }
  std::cout << reversed_sequence.size() - max << "\n";
  for (int i = max; i < reversed_sequence.size(); ++i) {
    std::cout << reversed_sequence[i] << " ";
  }
  return 0;
}