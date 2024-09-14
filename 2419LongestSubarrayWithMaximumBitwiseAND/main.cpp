#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int maxNum{INT_MIN};
    int len{0};
    int tempLen{0};

    for (int num : nums) {
      if (num > maxNum) {
        len = 1;
        tempLen = 1;
        maxNum = num;
      } else if (num == maxNum) {
        tempLen++;
      } else {
        len = max(len, tempLen);
        tempLen = 0;
      }
    }

    len = max(len, tempLen);

    return len;
  }
};
