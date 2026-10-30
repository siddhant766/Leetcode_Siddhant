#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // If k < 1, no character can be placed, so a path is impossible
        if (k < 1) return -1;
        
        // Build adjacency list: adj[u] = {(v, weight), ...}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // dist[u][c] stores the minimum weight to reach node u with consecutive count c
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
        
        // Priority queue stores elements as: {weight, u, count}
        // min-heap ordered by weight
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        // Base case: start at node 0 with consecutive count 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();
            
            // If we reached the destination node, it's the minimum total weight
            if (u == n - 1) return d;
            
            // Skip outdated states
            if (d > dist[u][c]) continue;
            
            // Traverse neighbors
            for (const auto& [v, w] : adj[u]) {
                int next_c = (labels[v] == labels[u]) ? (c + 1) : 1;
                
                // Only proceed if the consecutive count doesn't exceed k
                if (next_c <= k) {
                    if (d + w < dist[v][next_c]) {
                        dist[v][next_c] = d + w;
                        pq.push({dist[v][next_c], v, next_c});
                    }
                }
            }
        }
        
        return -1; // Destination unreachable under the given constraints
    }
};
