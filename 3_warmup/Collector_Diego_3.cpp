#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n, k;
  std::cin >> n;
  std::vector<int> diegos_collection(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> diegos_collection[i];
  }
  std::cin >> k;
  std::vector<int> others_collectors(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> others_collectors[i];
  }

  std::sort(diegos_collection.begin(), diegos_collection.end());
  std::vector<int> unique_cards_diego;
  unique_cards_diego.push_back(diegos_collection[0]);
  for (int i = 1; i < n; ++i) {
    if (diegos_collection[i] != diegos_collection[i - 1]) {
      unique_cards_diego.push_back(diegos_collection[i]);
    }
  }
  for (auto card : others_collectors) {
    std::cout << std::distance(unique_cards_diego.begin(), std::lower_bound(unique_cards_diego.begin(), unique_cards_diego.end(), card)) << "\n";
  }
  return 0;
}