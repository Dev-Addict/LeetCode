#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> frequency;

    for (int num : nums)
      frequency[num]++;

    sort(nums.begin(), nums.end(), [&](int a, int b) {
      return frequency[a] == frequency[b] ? a > b : frequency[a] < frequency[b];
    });

    return nums;
  }
};

