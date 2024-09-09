#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxPossibleScore(vector<int> &start, int d) {
    sort(start.begin(), start.end());

    int n = start.size();

    int low{0};
    int high{d};
    int answer{0};

    while (low <= high) {
      int mid = (low + high) / 2;

      if (canAchieveScore(start, d, mid)) {
        answer = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return answer;
  }

  bool canAchieveScore(vector<int> &start, int d, int mid) {
    int prev{start[0]};

    for (int i = 1; i < start.size(); ++i) {
      int nextPossible{prev + mid};

      if (nextPossible > start[i] + d) {
        return false;
      }

      prev = max(start[i] + d, nextPossible);
    }

    return true;
  }
};
