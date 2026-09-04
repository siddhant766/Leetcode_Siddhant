class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(
            m+1,
            vector<long long>(k+1,0)
        );
        for(int j=1;j<=m;j++){
            dp[j][1] = 1;
        }
        for(int len = 2;len<=n;len++){
            vector<vector<long long>> next(
                m+1,
                vector<long long>(k+1,0)
            );
            for(int maxVal = 1; maxVal <= m; maxVal++){
                for(int cost = 1; cost <= k; cost++){
                    if(dp[maxVal][cost] == 0){
                        continue;
                    }
                    next[maxVal][cost] =
                        (next[maxVal][cost]
                        +dp[maxVal][cost]*maxVal)% MOD;
                    
                    if(cost < k){
                        for(int newMax = maxVal +1;
                            newMax <= m;
                            newMax++){
                                next[newMax][cost +1]=
                                    (next[newMax][cost+1]
                                    + dp[maxVal][cost]) % MOD;
                            }
                    }

                }
            }
            dp = next;
        }
        long long ans = 0;
        for(int maxVal = 1;maxVal <= m;maxVal++){
            ans = (ans + dp[maxVal][k])%MOD;
        }
        return ans;
    }
};