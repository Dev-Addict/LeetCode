#include <algorithm>
using namespace std;

class Solution {
public:
  int minSteps(int n) {
    if (n == 1) return 0;

    int result = n;

    for (int i = 2; i * i <= n; ++i) 
      if (n % i == 0)
        result = min(result, minSteps(n / i) + i);

    return result;
  }
};
