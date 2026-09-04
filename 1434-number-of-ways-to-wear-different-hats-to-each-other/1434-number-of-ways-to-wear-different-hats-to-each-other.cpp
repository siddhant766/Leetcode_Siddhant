class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int MOD = 1e9 + 7;
        int n = hats.size();
        vector<vector<int>> hatToPeople(41);
        for(int person = 0; person < n; person++){
            for(int hat : hats[person]){
                hatToPeople[hat].push_back(person);
            }
        }
        int totalMasks = 1 << n;
        vector<long long> dp(totalMasks,0);
        dp[0] = 1;
        for(int hat = 1; hat <= 40; hat++){
            vector<long long> ndp = dp;
            for(int mask = 0;mask < totalMasks;mask++){
                if(dp[mask] == 0){
                    continue;
                }
                for(int person: hatToPeople[hat]){
                    if(mask & (1 << person)){
                        continue;
                    }

                    int newMask = mask | ( 1 << person);
                    ndp[newMask] = (ndp[newMask] + dp[mask]) % MOD;
                }
            }
            dp = ndp;
        }
        return dp[totalMasks - 1];
    }
};