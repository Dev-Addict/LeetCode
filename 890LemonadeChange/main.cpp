#include <vector>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int fiveBills = 0;
    int tenBills = 0;

    for (int bill : bills) {
      if (bill == 5) 
        fiveBills++;
      else if (bill == 10) {
        if (fiveBills == 0)
          return false;
        else {
          tenBills++;
          fiveBills--;
        }
      } else {
        if (tenBills > 0 && fiveBills > 0) {
          tenBills--;
          fiveBills--;
        } else if (fiveBills > 2) 
          fiveBills -= 3;
        else
         return false;
      }
    }

    return true;
  }
};
