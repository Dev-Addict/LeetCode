#include<vector>
using namespace std;

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    int maxVal = r;
    vector<int> properDivisorCount(maxVal + 1, 0);

    for (int i = 1; i <= maxVal; ++i)
      for (int j = 2 * i; j <= maxVal; j += i)
        properDivisorCount[j]++;

    int result = 0;

    for (int i = l; i <= r; ++i)
      if (properDivisorCount[i] != 2)
        result++;

    return result;
  }
};

