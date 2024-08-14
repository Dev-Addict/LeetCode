#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> prices) {
    int largestDifference = 0, n = prices.size();

    for (int distance = 1; distance < n; distance++) 
      for (int i = 0; i < n - distance + 1; i++) {
        int difference = prices[i + distance] - prices[i];

        if (difference > largestDifference)
          largestDifference = difference;
      }

    return largestDifference;
  }
};

