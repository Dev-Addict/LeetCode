#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    unordered_map<int, int> mappedNums;

    for (int num : nums)
      mappedNums[num] = mapNumber(mapping, to_string(num));

    sort(nums.begin(), nums.end(), [&](int a, int b) {
      return mappedNums[a] < mappedNums[b];
    });

    return nums;
  }

  int mapNumber(vector<int>&mapping, string num) {
    if (num.length() == 0)
      return 0;

    return mapping[num[num.length() - 1] - '0'] + mapNumber(mapping, num.substr(0, num.length() - 1)) * 10;
  }
};

