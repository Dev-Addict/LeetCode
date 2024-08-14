#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();

    k = k % n;

    if (k == 0)
      return;

    queue<int> initialNumbers;

    for (int i = n - k; i < n; i++)
      initialNumbers.push(nums[i]);

    for (int i = n - k - 1; i >= 0; i--)
      nums[i + k] = nums[i];

    for (int i = 0; i < k; i++) {
      nums[i] = initialNumbers.front();
      initialNumbers.pop();
    }
  }
};
