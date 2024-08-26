#include <vector>
using namespace std;

class Solution {
public:
  bool isGood(vector<int> &nums) {
    vector<int> repeats;

    for (int num: nums) {
      while (num > repeats.size()) {
        repeats.push_back(0);
      }

      if (repeats[num - 1] != 0 && num != repeats.size()) {
        return false;
      }

      ++repeats[num - 1];
    }

    if (repeats[repeats.size() - 1] != 2) {
      return false;
    }

    for (int i = 0; i < repeats.size() - 1; i++) {
      if (repeats[i] != 1) {
        return false;
      }
    }

    return true;
  }
};
