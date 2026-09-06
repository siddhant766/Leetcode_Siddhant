class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n = houses.size();
        vector<vector<int>> cost(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mid = (i+j)/2;
                for(int x =i;x<=j;x++){
                    cost[i][j] += abs(houses[x]-houses[mid]);
                }
            }
        }
        const int INF = 1e9;
        vector<vector<int>> dp(k+1,vector<int>(n+1,INF));
        dp[0][0] = 0;
        for(int m=1;m<=k;m++){
            for(int i=1;i<=n;i++){
                for(int j=0;j<i;j++){
                    if(dp[m-1][j] != INF){
                        dp[m][i] = min(dp[m][i],dp[m-1][j] + cost[j][i-1]);
                    }
                }
            }
        }
        return dp[k][n];










    }
};