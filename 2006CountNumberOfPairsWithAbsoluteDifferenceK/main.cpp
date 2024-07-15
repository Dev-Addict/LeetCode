#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    int result = 0;

    for (int num : nums)
      frequency[num]++;

    for (int num : nums)
      if (frequency.find(num + k) != frequency.end())
        result += frequency[num + k];

    return result;
  }
};

