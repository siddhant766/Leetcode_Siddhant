class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n,0);
        for(auto &r : relations)
            pre[r[1] -1] |= 1 << (r[0]-1);
        int total = 1 << n;
        vector<int> dp(total,INT_MAX);
        dp[0] =0;
        for(int mask = 0;mask<total;mask++){
            if(dp[mask] == INT_MAX)continue;
            int avilable = 0;
            for(int i=0;i<n;i++){
                if(!(mask & (1 << i)) && (pre[i] & mask) == pre[i])
                    avilable |= 1 << i;
            }
            if(__builtin_popcount(avilable) <= k){
                dp[mask | avilable] = min(dp[mask|avilable], dp[mask]+1);
            }else{
                for(int sub = avilable; sub;sub = (sub -1)&avilable){
                    if(__builtin_popcount(sub) == k){
                        dp[mask|sub] = min(dp[mask|sub],dp[mask]+1);
                    }
                }
            }

        }
        return dp[total -1];
    }
};