#include <vector>
using namespace std;

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;

    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m - 2; j++) {
        bool numExists[10] = {false};

        bool oneToNine = true;

        for (int k = i; k < i + 3; k++) {
          for (int l = j; l < j + 3; l++) {
            int val = grid[k][l];
            if (val < 1 || val > 9 || numExists[val]) {
              oneToNine = false;
              break;
            }
            numExists[val] = true;
          }
          if (!oneToNine)
            break;
        }

        if (!oneToNine)
          continue;

        int rowSum[3] = {0}, colSum[3] = {0}, diagonalSum[2] = {0};

        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            rowSum[k] += grid[i + k][j + l];
            colSum[k] += grid[i + l][j + k];
          }
          diagonalSum[0] += grid[i + k][j + k];
          diagonalSum[1] += grid[i + k][j + 2 - k];
        }

        bool rowEqual = rowSum[0] == rowSum[1] && rowSum[1] == rowSum[2];
        bool colEqual = colSum[0] == colSum[1] && colSum[1] == colSum[2];
        bool diagonalEqual = diagonalSum[0] == diagonalSum[1];

        if (rowEqual && colEqual && diagonalEqual && rowSum[0] == colSum[0] && colSum[0] == diagonalSum[0])
          count++;
      }
    }

    return count;
  }
};

