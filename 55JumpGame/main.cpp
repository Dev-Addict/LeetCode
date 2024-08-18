#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int maxReach = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      if (maxReach < i)
        return false;

      maxReach = max(nums[i] + i, maxReach);
    }

    return true;
  }
};
