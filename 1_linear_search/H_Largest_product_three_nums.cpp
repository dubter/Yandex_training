#include <iostream>

int main() {
  int num;
  int max, next_max, next_next_max;
  int min, next_min;
  int iteration = 1;
  while (std::cin >> num) {
    if (iteration == 1) {
      max = num;
      min = num;
    } else if (iteration == 2) {
      if (max < num) {
        next_max = max;
        max = num;
      } else {
        next_max = num;
      }

      if (min > num) {
        next_min = min;
        min = num;
      } else {
        next_min = num;
      }
    } else if (iteration == 3) {
      if (max < num) {
        next_next_max = next_max;
        next_max = max;
        max = num;
      } else if (next_max < num) {
        next_next_max = next_max;
        next_max = num;
      } else {
        next_next_max = num;
      }

      if (min > num) {
        next_min = min;
        min = num;
      } else if (next_min > num) {
        next_min = num;
      }
    } else {
      if (max < num) {
        next_next_max = next_max;
        next_max = max;
        max = num;
      } else if (next_max < num) {
        next_next_max = next_max;
        next_max = num;
      } else if (next_next_max < num) {
        next_next_max = num;
      }

      if (min > num) {
        next_min = min;
        min = num;
      } else if (next_min > num) {
        next_min = num;
      }
    }
    ++iteration;
  }

  if (static_cast<long long>(max) * next_max * next_next_max > static_cast<long long>(min) * next_min * max) {
    std::cout << next_next_max << " " <<next_max << " " << max;
  } else {
    std::cout << min << " " << next_min << " " << max;
  }
  return 0;
}