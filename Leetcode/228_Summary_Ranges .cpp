#include <vector>
#include <string>
#include "iostream"

class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> ans;
    std::string str = "";
    int left = 0;
    for (int right = 0; right < nums.size() - 1; ++right) {
      if (nums[right + 1] != nums[right] + 1) {
        if (left == right) {
          str += std::to_string(nums[left]);
        } else {
          str += std::to_string(nums[left]);
          str += "->";
          str += std::to_string(nums[right]);
        }
        ans.push_back(str);
        left = right + 1;
      }
      str = "";
    }

    if (left == nums.size() - 1) {
      str += std::to_string(nums[left]);
    } else {
      str = std::to_string(nums[left]);
      str += "->";
      str += std::to_string(nums[nums.size() - 1]);
    }
    ans.push_back(str);

    return ans;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums{0,2,3,5,6,8,9,0,1,2};
  std::vector<std::string> ans = sl.summaryRanges(nums);
  for (auto it : ans) {
    std::cout << it << "\n";
  }
  return 0;
}