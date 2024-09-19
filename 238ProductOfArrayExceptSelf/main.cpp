#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int productTotal = 1, zeroes = 0;

    for (int &num : nums) {
      if (num == 0)
        zeroes++;
      else
        productTotal *= num;
    }

    if (zeroes >= 2)
      return vector<int>(nums.size(), 0);

    vector<int> result(nums.size(), 0);

    if (zeroes == 1) {
      for (int i = 0; i < nums.size(); i++)
        if (nums[i] == 0) {
          result[i] = productTotal;

          return result;
        }
    }

    for (int i = 0; i < nums.size(); i++)
      result[i] = productTotal / nums[i];

    return result;
  }
};
