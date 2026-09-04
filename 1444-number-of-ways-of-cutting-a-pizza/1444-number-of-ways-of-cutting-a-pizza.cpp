class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>> pre(m+1,vector<int>(n+1,0));
        for(int i=m-1; i>= 0; i--){
            for(int j = n-1; j>= 0; j--){
                pre[i][j] = pre[i+1][j] 
                                + pre[i][j+1]
                                - pre[i+1][j+1]
                                + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(
            k,
            vector<vector<int>>(m,vector<int>(n,0))
        );
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pre[i][j] > 0)
                    dp[0][i][j] = 1;
            }
        }
        for(int peices = 1; peices<k;peices++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(pre[i][j] == 0){
                        continue;
                    }
                    for(int ni = i+1;ni<m;ni++){
                        if(pre[i][j] - pre[ni][j] > 0){
                            dp[peices][i][j] = 
                                (dp[peices][i][j] + dp[peices -1][ni][j])%MOD;
                        }
                    }
                    for(int nj = j+1; nj < n;nj++){
                        if(pre[i][j] - pre[i][nj] > 0){
                            dp[peices][i][j] = 
                                (dp[peices][i][j] + dp[peices-1][i][nj]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[k-1][0][0];
    }
};