#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  int minGroups(vector<vector<int>> &intervals) {
    size_t n{intervals.size()};
    vector<int> startPoses(n), endPoses(n);

    int i{};
    for (vector<int> &interval : intervals) {
      startPoses[i] = interval[0];
      endPoses[i] = interval[1];
      ++i;
    }

    sort(startPoses.begin(), startPoses.end());
    sort(endPoses.begin(), endPoses.end());

    int endPointer{};
    int result{};

    for (int startPos : startPoses) {
      if (startPos > endPoses[endPointer]) {
        endPointer++;
      } else {
        result++;
      }
    }

    return result;
  }
};
