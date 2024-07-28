#include<cmath>
using namespace std;

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    int result = 0;

    for (int i = l; i <= r; i++) {
      int properDivisors = 1, squareRoot = sqrt(i);

      for (int j = 2; j <= squareRoot; j++) {
        if (i % j == 0) {
          properDivisors += 1 + (j != i / j);
  
          if (properDivisors > 2)
            break;
        }
      }

      result += properDivisors != 2;
    }

    return result;
  }
};

