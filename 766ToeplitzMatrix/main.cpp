#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    size_t m{matrix.size()};
    size_t n{matrix[0].size()};
    size_t o{min(m, n)};

    for (int i{}; i < n; i++) {
      for (int j{1}; j < min(o, n - i); j++) {
        if (matrix[0][i] != matrix[j][i + j]) {
          return false;
        }
      }
    }

    for (int i{1}; i < m; i++) {
      for (int j{1}; j < min(o, m - i); j++) {
        if (matrix[i][0] != matrix[i + j][j]) {
          return false;
        }
      }
    }

    return true;
  }
};
