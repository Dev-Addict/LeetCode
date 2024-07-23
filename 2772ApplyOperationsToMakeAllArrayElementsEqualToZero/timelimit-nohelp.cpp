#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
  bool checkArray(vector<int>& nums, int k) {
    int n = nums.size(), i = 0;

    while (i + k <= n) {
      int operations = INT_MAX;
      long long sum = 0;

      for (int j = i; j < i + k; j++) {
        if (nums[j] < operations) 
          operations = nums[j];
        sum += nums[j];
      }

      if (operations == 0 && sum == 0) {
        i = i + k;
        continue;
      }


      int firstNonZero = i + k;

      for (int j = i; j < i + k; j++) {
        nums[j] -= operations;
        if (j < firstNonZero) {
          if (nums[j] != 0)
            firstNonZero = j;
        } else {
          if (nums[j] == 0)
            return false;
        }
      }

      i = firstNonZero;
    }

    for (; i < n; i++)
      if (nums[i] != 0)
        return false;

    return true;
  }
};

