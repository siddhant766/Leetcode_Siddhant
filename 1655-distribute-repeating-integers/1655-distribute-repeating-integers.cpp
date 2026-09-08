#include<vector>
#include<unordered_map>
#include<algorithm>
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> counts;
        for(int x : nums){
            counts[x]++;
        }
        vector<int> count;
        for(auto& [_,c] : counts){
            count.push_back(c);
        }
        int m = quantity.size();
        int num_subsets = 1 << m;
        vector<int> sum(num_subsets, 0);
        for(int mask =0; mask < num_subsets; ++mask){
            for(int i=0;i<m;++i){
                if(mask & (1 << i)){
                    sum[mask] += quantity[i];
                }
            }
        }
        vector<bool> dp(num_subsets, false);
        dp[0] = true;
        for(int c: count){
            for(int mask = num_subsets -1;mask >= 0; --mask){
                if(dp[mask]) continue;
                for(int sub = mask; sub > 0; sub = (sub -1) & mask){
                    if(sum[sub] <= c && dp[mask ^ sub]){
                        dp[mask]=true;
                        break;
                    }
                } 
            }
            if(dp[num_subsets -1])return true;
        }
        return dp[num_subsets-1];
    }
};