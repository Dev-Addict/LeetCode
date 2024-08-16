#include <cstdlib>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    int minNum = INT_MAX, minIndex = 0, maxNum = INT_MIN, maxIndex = 0, secondMin, secondMax;

    for (int i = 0; i < arrays.size(); i++) {
      int size = arrays[i].size();

      if (minNum >= arrays[i][0]) {
        secondMin = minNum;
        minNum = arrays[i][0];
        minIndex = i;
      } else if (secondMin > arrays[i][0]) {
        secondMin = arrays[i][0];
      }

      if (maxNum <= arrays[i][size - 1]) {
        secondMax = maxNum;
        maxNum = arrays[i][size - 1];
        maxIndex = i;
      } else if (secondMax < arrays[i][size - 1]) {
        secondMax = arrays[i][size - 1];
      }
    }

    if (minIndex != maxIndex)
      return abs(maxNum - minNum);
    return max(abs(secondMax - minNum), abs(maxNum - secondMin));
  }
};
