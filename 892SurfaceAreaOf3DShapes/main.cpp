#include<vector>
using namespace std;

class Solution {
public:
  int surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size(), surfaceArea = n * n * 2;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int num = grid[i][j];

        if (num == 0)
          surfaceArea -= 2;
        else
          surfaceArea += max(0, num - getValueOfGrid(grid, n, i - 1, j)) + 
                         max(0, num - getValueOfGrid(grid, n, i, j + 1)) +
                         max(0, num - getValueOfGrid(grid, n, i + 1, j)) +
                         max(0, num - getValueOfGrid(grid, n, i, j - 1));
      }

    return surfaceArea;
  }

  int getValueOfGrid(vector<vector<int>>& grid, int n, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j>= n)
      return 0;
    return grid[i][j];
  }
};

