#include <vector>

class Solution {
 public:
  int maxDistToClosest(std::vector<int>& seats) {
    int count0 = 0;
    int max_count0 = 0;
    for (int i = 0; i < seats.size(); ++i) {
      if (seats[i] == 0) {
        count0++;
        if (max_count0 < count0) {
          max_count0 = count0;
        }
      } else {
        count0 = 0;
      }
    }

    // amount 0 at start
    int count0AtStart = 0;
    for (int i = 0; i < seats.size(); ++i) {
      if (seats[i] == 0) {
        count0AtStart++;
      } else {
        break;
      }
    }

    // amount 0 in the end
    int countInEnd = 0;
    for (int i = seats.size() - 1; i >= 0; --i) {
      if (seats[i] == 0) {
        countInEnd++;
      } else {
        break;
      }
    }
    return std::max(std::max(countInEnd, count0AtStart), (max_count0 + 1) / 2);
  }
  };