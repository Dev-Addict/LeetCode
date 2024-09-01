#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    if (original.size() != m * n) {
      return {};
    }

    vector<vector<int>> result(m);

    for (int i = 0; i < m; i++) {
      result[i] =
          vector<int>(original.begin() + i * n, original.begin() + (i + 1) * n);
    }

    return result;
  }
};
