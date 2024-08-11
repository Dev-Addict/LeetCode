#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countCompleteDayPairs(vector<int> &hours) {
    unordered_map<int, int> hourRemainders;

    for (int hour : hours)
      hourRemainders[hour % 24]++;

    int completeDayPairs = hourRemainders[0] * (hourRemainders[0] - 1) / 2;

    for (int i = 1; i < 12; i++)
      completeDayPairs += hourRemainders[i] * hourRemainders[24 - i];

    completeDayPairs += hourRemainders[12] * (hourRemainders[12] - 1) / 2;

    return completeDayPairs;
  }
};
