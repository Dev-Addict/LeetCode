#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> resultsArray(vector<vector<int>> &queries, int k) {
    priority_queue<int> max_heap;
    vector<int> results;

    for (const auto &query : queries) {
      int distance = abs(query[0]) + abs(query[1]);

      max_heap.push(distance);

      if (max_heap.size() > k) {
        max_heap.pop();
      }

      if (max_heap.size() < k) {
        results.push_back(-1);
      } else {
        results.push_back(max_heap.top());
      }
    }

    return results;
  }
};
