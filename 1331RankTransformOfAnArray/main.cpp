#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sortedArr(arr);
    unordered_map<int, int> bridge;

    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()),
                    sortedArr.end());

    for (int i = arr.size() - 1; i >= 0; i--) {
      bridge[sortedArr[i]] = i + 1;
    }

    for (int i = 0; i < arr.size(); i++) {
      arr[i] = bridge[arr[i]];
    }

    return arr;
  }
};
