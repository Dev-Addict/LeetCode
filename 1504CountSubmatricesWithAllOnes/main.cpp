#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> graph(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (mat[i][j] == 1)
          graph[i][j] = graph[i][min(0, j - 1)];

    int result = 0;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        int minCount = INT_MAX;

        for (int k = i; k >= 0 && minCount > 0; k--) {
          minCount = min(minCount, graph[k][j]);
          result += minCount;
        }
      }

    return result;
  }
};

