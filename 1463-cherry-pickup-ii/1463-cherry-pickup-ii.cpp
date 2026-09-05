class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[0][n-1] = grid[0][0] + grid[0][n-1];
        for(int row = 1 ;row<m;row++){
            vector<vector<int>> next(n,vector<int>(n,-1));
            for(int col1=0;col1<n;col1++){
                for(int col2=0;col2<n;col2++){
                    if(dp[col1][col2] == -1){
                        continue;
                    }
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int newCol1 = col1+d1;
                            int newCol2 = col2+d2;
                            if(newCol1 < 0 || newCol1 >= n || 
                                newCol2 <0 || newCol2 >= n){
                                    continue;
                                }
                            int cherries = dp[col1][col2];
                            cherries += grid[row][newCol1];
                            if(newCol1 != newCol2){
                                cherries += grid[row][newCol2];
                            }
                            next[newCol1][newCol2] = max(next[newCol1][newCol2], cherries);
                        }
                    }
                }
            }
            dp = next;
        }
        int ans = 0;
        for(int col1=0;col1<n;col1++){
            for(int col2=0;col2<n;col2++){
                ans = max(ans,dp[col1][col2]);
            }
        }
        return ans;

    }
};