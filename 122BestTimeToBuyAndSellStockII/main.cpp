#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int totalProfit{0};

    for (int i = 1; i < prices.size(); i++) 
      totalProfit += max(0, prices[i] - prices[i - 1]);

    return totalProfit;
  }
};
