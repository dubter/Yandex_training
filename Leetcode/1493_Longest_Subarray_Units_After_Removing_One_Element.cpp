#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    int max_count = 0;
    int count = 0;
    int right = 0;
    int substain = 0;
    for (int left = 0; left < nums.size() && right < nums.size(); ++left) {
      while (substain <= 1 && right < nums.size()) {
        if (nums[right] == 0) {
          substain++;
        } else {
          count++;
          if (max_count < count) {
            max_count = count;
          }
        }
        right++;
      }
      if (substain > 1) {
        substain--;
        right--;
      }
      if (nums[left] == 0) {
        substain--;
      } else {
        count--;
      }
    }

    if (max_count == nums.size()) {
      return nums.size() - 1;
    }
    return max_count;
  }
};