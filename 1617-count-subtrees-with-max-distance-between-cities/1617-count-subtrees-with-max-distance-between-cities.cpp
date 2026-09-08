#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& edge : edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n-1,0);
        for(int mask =1;mask<(1<<n);++mask){
            if((mask & (mask -1)) == 0)continue;
            int root = 0;
            while((mask & ( 1 << root)) == 0 )root++;
            auto bfs = [&](int start) -> pair<int,int>{
                queue<int> q;
                vector<int> dist(n,-1);
                q.push(start);
                dist[start] = 0;
                int farthest = start;
                int visited_mask = 0;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    visited_mask |= (1<<u);
                    for(int v: adj[u]){
                        if((mask & (1 << v)) && dist[v] == -1){
                            dist[v] = dist[u] + 1;
                            if(dist[v] > dist[farthest]){
                                farthest = v;
                            }
                            q.push(v);
                        }
                    }
                }
                return {farthest, visited_mask};
            };
            auto [farthest1,visited_mask] = bfs(root);
            if(visited_mask != mask) continue;
            auto bfs_dist = [&](int start) -> int{
                queue<int> q;
                vector<int> dist(n,-1);
                q.push(start);
                dist[start] = 0;
                int max_d = 0;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int v: adj[u]){
                        if((mask & (1 << v)) && dist[v] == -1){
                            dist[v] = dist[u] +1;
                            max_d = max(max_d,dist[v]);
                            q.push(v);
                        }
                    }
                }
                return max_d;
            };
            int diameter = bfs_dist(farthest1);
            if(diameter > 0){
                ans[diameter-1]++;
            }
        }
        return ans;
        
    }
};