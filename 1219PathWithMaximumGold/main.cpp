#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> directions = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0 , -1}
  };

  int getMaximumGold(vector<vector<int>>& grid) {
    int maxGold = 0;

    for (int i = 0; i < grid.size(); ++i) 
      for (int j = 0; j < grid[0].size(); ++j) 
        maxGold = max(maxGold, dfs(i, j, grid));

    return maxGold;
  }

private:
  int dfs(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
      return 0;

    int gold = grid[x][y];
    grid[x][y] = 0;

    int maxGoldFromHere = 0;

    for (int i = 0; i < 4; i++) {
      int nextGold = dfs(x + directions[i][0], y + directions[i][1], grid);

      maxGoldFromHere = max(maxGoldFromHere, gold + nextGold);
    }

    grid[x][y] = gold;

    return maxGoldFromHere;
  }
};

