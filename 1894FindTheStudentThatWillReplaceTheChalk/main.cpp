#include <vector>
using namespace std;

class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    int n = chalk.size();
    int sum{0};

    for (int num : chalk) {
      sum += num;
    }

    k = k % sum;

    int i{0};

    while (chalk[i] <= k) {
      k -= chalk[i];
      i = (i + 1) % n;
    }

    return i;
  }
};
