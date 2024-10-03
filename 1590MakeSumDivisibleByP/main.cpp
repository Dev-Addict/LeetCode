#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    size_t n{nums.size()};
    long sum{};

    for (int num : nums) {
      sum += num;
    }

    int remainder = sum % p;

    if (remainder == 0) {
      return 0;
    }

    unordered_map<int, int> prefix;
    long prefixSum{};
    int minLength = n;

    prefix[0] = -1;

    for (int i = 0; i < n; i++) {
      prefixSum += nums[i];

      int currentMod = prefixSum % p;
      int targetMod = (currentMod - remainder + p) % p;

      if (prefix.find(targetMod) != prefix.end()) {
        minLength = min(minLength, i - prefix[targetMod]);
      }

      prefix[currentMod] = i;
    }

    if (minLength == n) {
      return -1;
    }
    return minLength;
  }
};
