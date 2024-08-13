#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int majority, majorityCount = 0;

    for (int num : nums) {
      if (majorityCount == 0)
        majority = num;

      majorityCount += num == majority ? 1 : -1;
    }

    return majority;
  }
};
