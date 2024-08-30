#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> result;

    int start{0};
    int current{0};

    while (current < nums.size()) {
      while (current < nums.size() - 1 && nums[current + 1] == nums[current] + 1) {
        ++current;
      }

      if (current == start) {
        result.push_back(to_string(nums[start]));
      } else {
        result.push_back(to_string(nums[start]) + "->" + to_string(nums[current]));
      }

      ++current;
      start = current;
    }

    return result;
  }
};
