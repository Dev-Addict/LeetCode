#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
  long long findMaximumScore(vector<int> &nums) {
    int n = nums.size();

    vector<long long> dp(n, 0);

    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < n; i++) {
      dp[i] = dp[dq.front()] + (i - dq.front()) * nums[dq.front()];

      while (!dq.empty() && dp[i] >= dp[dq.back()] + (i - dq.back()) * nums[dq.back()]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    return dp[n - 1];
  }
};

