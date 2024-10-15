#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gains) {
    int currentAltitude{};
    int result{};

    for (int gain : gains) {
      currentAltitude += gain;
      result = max(currentAltitude, result);
    }

    return result;
  }
};
