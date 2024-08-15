#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    unordered_map<int, int> availableBills = {{5, 0}, {10, 0}, {20, 0}};

    for (int bill : bills) {
      availableBills[bill]++;

      int returnValue = bill - 5;

      if (returnValue >= 10)
        if (availableBills[10]) {
          returnValue -= 10;
          availableBills[10]--;
        }

      int fiveBills = returnValue / 5;

      if (availableBills[5] < fiveBills)
        return false;

      availableBills[5] -= fiveBills;
    }

    return true;
  }
};
