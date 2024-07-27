#include<algorithm>
#include<string>
#include<vector>
using namespace std;

const int INF = 1e7;

class Solution {
public:
  long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    vector<vector<int>> costs(26, vector<int>(26, INF));

    for (int i = 0; i < 26; i++)
      costs[i][i] = 0;

    for (int i = 0; i < original.size(); i++) {
      int from = original[i] - 'a';
      int to = changed[i] - 'a';

      costs[from][to] = min(costs[from][to], cost[i]);
    }

    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        for (int k = 0; k < 26; k++)
          costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);

    long long totalCost = 0;

    for (int i = 0; i < source.length(); i++) {
      int changeCost = costs[source[i] - 'a'][target[i] - 'a'];

      if (changeCost >= INF)
        return -1;

      totalCost += changeCost;
    }

    return totalCost;
  }
};

