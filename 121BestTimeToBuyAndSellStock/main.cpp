#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> prices) {
    int buyPrice = prices[0], maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (buyPrice > prices[i])
        buyPrice = prices[i];

      maxProfit = max(prices[i] - buyPrice, maxProfit);
    }

    return maxProfit;
  }
};
