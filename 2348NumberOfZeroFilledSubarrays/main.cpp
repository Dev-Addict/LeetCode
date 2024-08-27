#include <vector>
using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    vector<long long> continuousAppearences;
    int n = nums.size();
    int i = 0;

    while (i < n) {
      if (nums[i] == 0) {
        long long count = 1;

        while (i + count < n && nums[i + count] == 0) {
          count++;
        }

        i += count;
        continuousAppearences.push_back(count);
      } else {
        i++;
      }
    }

    long long result = 0;

    for (long long appearance : continuousAppearences) {
      result += appearance * (appearance + 1) / 2;
    }

    return result;
  }
};
