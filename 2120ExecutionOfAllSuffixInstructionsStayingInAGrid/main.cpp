#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPosition, string s) {
    vector<int> result{};
    int m{int(s.size())};

    for (int i = 0; i < m; ++i) {
      vector<int> currentPosition{startPosition};
      int count{0};

      for (int j = i; j < m; ++j) {
        if (move(n, currentPosition, s[j])) {
          ++count;
        } else {
          break;
        }
      }

      result.push_back(count);
    }

    return result;
  }

  bool move(int n, vector<int> &currentPosition, char instruction) {
    int row{currentPosition[0]};
    int col{currentPosition[1]};

    if (instruction == 'U') {
      --row;
    } else if (instruction == 'R') {
      ++col;
    } else if (instruction == 'D') {
      ++row;
    } else {
      --col;
    }

    if (row < 0 || row >= n || col < 0 || col >= n) {
      return false;
    }

    currentPosition[0] = row;
    currentPosition[1] = col;

    return true;
  }
};
