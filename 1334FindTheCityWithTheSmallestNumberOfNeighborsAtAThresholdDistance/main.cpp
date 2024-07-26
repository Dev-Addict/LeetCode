#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e5;

class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
      adj[edge[0]].emplace_back(edge[1], edge[2]);
      adj[edge[1]].emplace_back(edge[0], edge[2]);
    }

    auto dijkstra = [&](int src) {
      vector<int> dist(n, INF);
      dist[src] = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.emplace(0, src);

      while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (const auto& [v, weight] : adj[u]) {
          if (dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
            pq.emplace(dist[v], v);
          }
        }
      }

      return dist;
    };

    int minReachable = n;
    int resultCity = 0;

    for (int i = 0; i < n; ++i) {
      auto distances = dijkstra(i);
      int reachableCities = count_if(distances.begin(), distances.end(),
                                       [&](int d) { return d <= distanceThreshold; });

      if (reachableCities < minReachable) {
        minReachable = reachableCities;
        resultCity = i;
      } else if (reachableCities == minReachable) {
        resultCity = max(resultCity, i);
      }
    }

    return resultCity;
  }
};
