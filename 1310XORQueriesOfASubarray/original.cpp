#include <vector>
using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = queries.size();
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
      vector<int> query = queries[i];
      int queryAnswer = arr[query[0]];

      for (int i = query[0] + 1; i <= query[1]; i++) {
        queryAnswer ^= arr[i];
      }

      answer[i] = queryAnswer;
    }

    return answer;
  }
};
