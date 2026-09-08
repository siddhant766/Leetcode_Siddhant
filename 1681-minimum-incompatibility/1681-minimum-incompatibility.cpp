#include<vector>
#include<algorithm>
#include<climits>

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = n /k;
        if(sz == 1)return 0;
        vector<int>count(17,0);
        for(int x:nums){
            if(++count[x] > k)return -1;
        }
        vector<int> cost( 1 << n , -1);
        for(int mask = 1; mask < ( 1 << n); ++mask){
            if(__builtin_popcount(mask) != sz)continue;
            int min_val = 17,max_val = 0;
            int used_vals = 0;
            bool valid = true;
            for(int i = 0;i<n;++i){
                if(mask & ( 1 << i)){
                    if(used_vals & ( 1 << nums[i])){
                        valid = false;
                        break;
                    }
                    used_vals |= ( 1 << nums[i]);
                    min_val = min(min_val,nums[i]);
                    max_val = max(max_val, nums[i]);
                }
            }
            if(valid){
                cost[mask] = max_val - min_val;
            }
        }
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for(int mask = 0; mask < ( 1 << n) ; ++mask){
            if(dp[mask] == -1)continue;
            int remaining = ((1 << n) - 1) ^ mask;
            for(int sub = remaining; sub > 0; sub = (sub-1) & remaining){
                if(cost[sub] != -1){
                    int next_mask = mask | sub;
                    if(dp[next_mask] == -1 || dp[next_mask] > dp[mask] + cost[sub]){
                        dp[next_mask] = dp[mask] + cost[sub];
                    }
                }
            }
        }
        return dp[(1 << n) -1];
    }
};