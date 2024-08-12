#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    map<int, int> numRepeats;

    for (int num: nums)
      numRepeats[num]++;

    int result = 0;

    for (auto& pair:numRepeats) {
      int result_pair = min(2, pair.second);

      for (int i = 0; i < result_pair; i++) {
        nums[result + i] = pair.first;
      }

      result += result_pair;
    }

    return result;
  }
};
