#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int INF = 1e5;

class City {
public:
    int num;
    unordered_map<int, int> routes;

    City(int n) {
        this->num = n;
    }

    void addRoute(int n, int distance) {
        routes[n] = distance;
    }
};

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<City> cities;

        for (int i = 0; i < n; i++) {
            cities.emplace_back(i);
        }

        for (auto& edge : edges) {
            cities[edge[0]].addRoute(edge[1], edge[2]);
            cities[edge[1]].addRoute(edge[0], edge[2]);
        }

        int minRoutes = INF, minCityIndex = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int routes = findRoutes(cities[i], cities, distanceThreshold, 0, visited);

            if (routes <= minRoutes) {
                minRoutes = routes;
                minCityIndex = i;
            }
        }

        return minCityIndex;
    }

private:
    int findRoutes(City& city, vector<City>& cities, int distanceThreshold, int sumDistance, vector<bool>& visited) {
        visited[city.num] = true;
        int result = 0;

        for (auto& route : city.routes) {
            if (sumDistance + route.second <= distanceThreshold && !visited[route.first]) {
                result++;
                result += findRoutes(cities[route.first], cities, distanceThreshold, sumDistance + route.second, visited);
            }
        }

        return result;
    }
};

