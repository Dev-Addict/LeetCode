#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
  long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    long long differences = 0, adjustments = 0;

    for (int i = 0; i < nums1.size(); i++) {
      differences += abs(nums1[i] - nums2[i]);
      adjustments += nums1[i] - nums2[i];

      if (k != 0 && differences % k != 0)
        return -1;
    }

    if (k == 0) {
      if (differences == 0)
        return 0;
      return -1;
    }
    if (differences % (2 * k) == 0)
      if (adjustments == 0)
      return differences / (2 * k);
    return -1;
  }
};

