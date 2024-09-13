#include <vector>
using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> processed(n);

    processed[0] = arr[0];

    for (int i = 1; i < n; i++) {
      processed[i] = processed[i - 1] ^ arr[i];
    }

    int m = queries.size();
    vector<int> answer(m);

    for (int i = 0; i < m; i++) {
      int left = queries[i][0];
      int right = queries[i][1];

      if (left == 0) {
        answer[i] = processed[right];
      } else {
        answer[i] = processed[right] ^ processed[left - 1];
      }
    }

    return answer;
  }
};
