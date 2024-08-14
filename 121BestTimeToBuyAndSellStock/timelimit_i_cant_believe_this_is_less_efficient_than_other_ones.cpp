#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> prices) {
    if (prices.size() < 2)
      return 0;

    int smallestLeft = prices[0], n = prices.size(),
        biggestRight = findBiggestRight(prices, n, 1),
        maxProfit = biggestRight - smallestLeft;

    for (int i = 1; i < n - 1; i++) {
      if (smallestLeft > prices[i])
        smallestLeft = prices[i];
      if (biggestRight == prices[i - 1])
        biggestRight = findBiggestRight(prices, n, i + 1);

      int profit = biggestRight - smallestLeft;

      if (profit > maxProfit)
        maxProfit = profit;
    }

    return max(maxProfit, 0);
  }

private:
  int findBiggestRight(vector<int> &prices, int n, int begin) {
    int biggestRight = INT_MIN;

    for (int i = begin; i < n; i++)
      if (prices[i] > biggestRight)
        biggestRight = prices[i];

    return biggestRight;
  }
};

