#include<vector>
using namespace std;

class Solution {
public:
  bool checkArray(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0;
    vector<int> differences(n + 1);

    for (int i = 0; i < n; i++) {
      sum += differences[i];
      nums[i] += sum;

      if (nums[i] == 0)
        continue;

      if (nums[i] < 0 || i + k > n)
        return false;

      sum -= nums[i];
      differences[i + k] = nums[i];
    }

    return true;
  }
};

