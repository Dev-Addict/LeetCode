#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
  int firstBadVersion(int n) {
    return findFirstBadVersion(n / 2, n / 2 + 1);
  }

  int findFirstBadVersion(int n, int swing) {
    if (swing <= 2) {
      if (isBadVersion(n))
        return n;
      if (isBadVersion(n + 1))
        return n + 1;
      if (isBadVersion(n + 2))
        return n + 2;
      else
        return INT_MAX;
    }
    if (isBadVersion(n))
      return min(n, findFirstBadVersion(n - swing / 2, swing / 2 + 1));
    return findFirstBadVersion(n + swing / 2, swing / 2 + 1);
  }
};

