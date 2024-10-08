#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    int pointer2 = 0, pointer3 = 0, pointer5 = 0;

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      int next2 = dp[pointer2] * 2, next3 = dp[pointer3] * 3,
          next5 = dp[pointer5] * 5;

      dp[i] = min(next2, min(next3, next5));

      if (dp[i] == next2)
        ++pointer2;
      if (dp[i] == next3)
        ++pointer3;
      if (dp[i] == next5)
        ++pointer5;
    }

    return dp[n - 1];
  }
};
