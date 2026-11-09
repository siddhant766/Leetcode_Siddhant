#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        
        // available: stores IDs of currently idle servers
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // busy: min-heap storing {finish_time, server_id}
        // Using long long for finish_time to avoid potential overflow (arrival[i] + load[i] <= 2 * 10^9)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        
        vector<int> request_count(k, 0);
        
        for (int i = 0; i < n; ++i) {
            long long cur_time = arrival[i];
            long long duration = load[i];
            
            // Free up all servers that finished their tasks before or at cur_time
            while (!busy.empty() && busy.top().first <= cur_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If no servers are available, the request is dropped
            if (available.empty()) {
                continue;
            }
            
            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available.lower_bound(target);
            
            // If none found >= target, wrap around to the first available server
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server_id = *it;
            available.erase(it);
            
            busy.emplace(cur_time + duration, server_id);
            request_count[server_id]++;
        }
        
        // Find the busiest server(s)
        int max_requests = *max_element(request_count.begin(), request_count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};