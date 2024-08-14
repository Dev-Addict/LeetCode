#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int largestDifference = 0, n = prices.size();

    for (int i = 0; i < n - 1; i++) 
      for (int j = i + 1; j < n; j++) {
        int difference = prices[j] - prices[i];

        if (difference > largestDifference)
          largestDifference = difference;
      }

    return largestDifference;
  }
};

