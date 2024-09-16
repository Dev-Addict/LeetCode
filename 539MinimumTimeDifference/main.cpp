#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    int n = timePoints.size();
    vector<int> minutes(n);

    for (int i = 0; i < n; ++i) {
      minutes[i] =
          stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3));
    }

    sort(minutes.begin(), minutes.end());

    int result = minutes[1] - minutes[0];

    for (int i = 2; i < n; ++i) {
      result = min(result, minutes[i] - minutes[i - 1]);
    }

    return min(result, 1440 - minutes.back() + minutes.front());
  }
};
