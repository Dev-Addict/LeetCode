#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size();
    int m = colSum.size();

    vector<vector<int>> result = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (rowSum[i] == 0 || colSum[j] == 0)
          continue;

        int value = min(rowSum[i], colSum[j]);

        result[i][j] = value;

        rowSum[i] -= value;
        colSum[j] -= value;
      }

    return result;
  }
};

