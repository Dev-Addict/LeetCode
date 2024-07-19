#include<vector>
using namespace std;

class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> minNumRow = vector<int>(matrix.size(), 0);
    vector<int> maxNumColumn = vector<int>(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
      for (int j = 1; j < matrix[i].size(); j++)
        if (matrix[i][j] < matrix[i][minNumRow[i]])
         minNumRow[i] = j;

    for (int i = 0; i < matrix[0].size(); i++)
      for (int j = 1; j < matrix.size(); j++)
        if (matrix[j][i] > matrix[maxNumColumn[i]][i])
          maxNumColumn[i] = j;

    vector<int> result;

    for (int i = 0; i < matrix.size(); i++)
      if (i == maxNumColumn[minNumRow[i]])
        result.push_back(matrix[i][minNumRow[i]]);

    return result;
  }
};

