#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int vals = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == val) 
        vals++;
      else
        nums[i - vals] = nums[i];
    }

    return n - vals;
  }
};
