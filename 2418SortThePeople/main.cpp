#include<algorithm>
#include<numeric>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();

    vector<int>indicies(n);
    iota(indicies.begin(), indicies.end(), 0);

    sort(indicies.begin(), indicies.end(), [&](int a, int b) {
      return heights[a] > heights[b];
    });

    vector<string> result;

    for (int i = 0; i < n; i++) 
      result.push_back(names[indicies[i]]);

    return result;
  }
};

