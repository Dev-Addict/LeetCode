#include<vector>
using namespace std;

class neighborSum {
  vector<vector<int>> grid;
  int n;

public:
  neighborSum(vector<vector<int>>& g) {
    grid = g;
    n = g.size();
  }
    
  int adjacentSum(int value) {
    int i = 0, j = 0;

    for (; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (grid[i][j] == value) {
          break;
        }
      }
      if (j < n && grid[i][j] == value) break; 
    }

    return getValueAt(i - 1, j) + getValueAt(i, j + 1) + getValueAt(i + 1, j) + getValueAt(i, j - 1);
  }
    
  int diagonalSum(int value) {
    int i = 0, j = 0;

    for (; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (grid[i][j] == value) {
          break;
        }
      }
      if (j < n && grid[i][j] == value) break; 
    }

    return getValueAt(i + 1, j + 1) + getValueAt(i - 1, j + 1) + getValueAt(i + 1, j - 1) + getValueAt(i - 1, j - 1);
  }

  int getValueAt(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n)
      return 0;
    return grid[i][j];
  }
};

