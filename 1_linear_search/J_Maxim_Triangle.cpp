#include <iostream>
#include <iomanip>

int main() {
  int amount_frequency;
  std::cin >> amount_frequency;
  double frequency, last_frequency;
  double min_frequency_triangle = 30.0, max_frequency_triangle = 4000.0;
  std::string mod;
  for (int i = 0; i < amount_frequency; ++i) {
    std::cin >> frequency;
    if (i != 0) {
      std::cin >> mod;
      double middle = (last_frequency + frequency) / 2;
      if ( last_frequency > frequency && mod == "closer" || last_frequency < frequency && mod == "further") {
        if (max_frequency_triangle > middle) {
          max_frequency_triangle = middle;
        }

      } else if (last_frequency > frequency && mod == "further" || last_frequency < frequency && mod == "closer") {
        if (min_frequency_triangle < middle) {
          min_frequency_triangle = middle;
        }
      }
    }
    last_frequency = frequency;
  }
  std::cout << std::setprecision(6) << std::fixed;
  std::cout << min_frequency_triangle << " " << max_frequency_triangle;
  return 0;
}