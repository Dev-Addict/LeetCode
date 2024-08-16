#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int repeats = 0, n = nums.size();

    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1])
        repeats++;
      else 
        nums[i - repeats] = nums[i];
    }

    return n - repeats;
  }
};

