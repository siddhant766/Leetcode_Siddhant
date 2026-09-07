#include<vector>
#include<algorithm>
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        std::vector<std::vector<long long>> max_dp(m, std::vector<long long>(n));
        std::vector<std::vector<long long>> min_dp(m, std::vector<long long>(n));
        max_dp[0][0] = min_dp[0][0] = grid[0][0];
        for(int i=1;i<m;++i){
            max_dp[i][0] = min_dp[i][0] = max_dp[i-1][0] * grid[i][0];
        }
        for(int j=1;j<n;++j){
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j-1] * grid[0][j];
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                long long val = grid[i][j];
                long long a = max_dp[i-1][j] * val;
                long long b = min_dp[i-1][j] * val;
                long long c = max_dp[i][j-1] * val;
                long long d = min_dp[i][j-1] * val;

                max_dp[i][j] = std::max({a,b,c,d});
                min_dp[i][j] = std::min({a,b,c,d});
            }
        }
        long long ans = max_dp[m-1][n-1];
        return ans < 0 ? -1 : ans % MOD;
    }
};