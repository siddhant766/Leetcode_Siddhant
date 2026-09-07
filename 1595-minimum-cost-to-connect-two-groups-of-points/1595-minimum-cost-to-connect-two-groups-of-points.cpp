#include<vector>
#include<algorithm>
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int sz1 = cost.size();
        int sz2 = cost[0].size();
        int max_mask = 1 << sz2;
        std::vector<int> min_cost_sz2(sz2,1e9);
        for(int j=0; j<sz2; ++j){
            for(int i=0; i< sz1; ++i){
                min_cost_sz2[j] = std::min(min_cost_sz2[j], cost[i][j]);
            }
        }
        std::vector<int> dp(max_mask, 1e9);
        dp[0] = 0;
        for(int i=0;i<sz1;++i){
            std::vector<int> next_dp(max_mask, 1e9);
            for(int mask = 0; mask < max_mask; ++mask){
                if(dp[mask] == 1e9)continue;
                for(int j=0; j<sz2; ++j){
                    next_dp[mask | (1 << j)] = std::min(next_dp[mask | (1 <<j)],
                    dp[mask]+cost[i][j]);    
                }
            }
            for(int mask =0;mask <max_mask; ++mask){
                if(next_dp[mask] == 1e9)continue;
                for(int j=0;j<sz2; ++j){
                    next_dp[mask | (1 <<j )] = std ::min(next_dp[mask | (1 << j)], next_dp[mask]+cost[i][j]);
                }
            }
            dp = std::move(next_dp);
        }
        int ans = 1e9;
        for(int mask =0;mask <max_mask;++mask){
            if(dp[mask] == 1e9)continue;
            int total = dp[mask];
            for(int j =0; j<sz2;++j){
                if(!(mask & (1<<j))){
                    total += min_cost_sz2[j];
                }
            }
            ans = std::min(ans,total);
        }
        return ans;
    }
};