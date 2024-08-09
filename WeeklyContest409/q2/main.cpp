#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++)
      graph[i].push_back(i + 1);

    vector<int> result;

    for (vector<int>& query : queries) {
      graph[query[0]].push_back(query[1]);
      result.push_back(bfs(n, graph, 0, n - 1));
    }

    return result;
  }

  int bfs(int n, vector<vector<int>> graph, int source, int destination) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    q.push(source);

    dist[source] = 0;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      if (node == destination)
        return dist[node];

      for (int neighbor : graph[node]) 
        if (dist[neighbor] == INT_MAX) {
          dist[neighbor] = dist[node] + 1;
          q.push(neighbor);
        }
    }

    return -1;
  }
};

