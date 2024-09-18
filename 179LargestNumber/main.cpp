#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [&](int a, int b) {
      string sa{to_string(a)};
      string sb{to_string(b)};

      return sa + sb > sb + sa;
    });

    if (nums[0] == 0) {
      return "0";
    }

    ostringstream result;

    for (int num : nums) {
      result << num;
    }

    return result.str();
  }
};
