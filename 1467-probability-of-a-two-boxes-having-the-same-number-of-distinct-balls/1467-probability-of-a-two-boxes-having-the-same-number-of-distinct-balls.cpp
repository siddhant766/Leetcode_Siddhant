class Solution {
public:
    double getProbability(vector<int>& balls) {
        int n = balls.size();
        int total = 0;
        for(int x:balls){
            total += x;
        }
        int half = total / 2;
        vector<vector<double>> dp(
            half+1,
            vector<double>(2*n+1,0.0)
        );
        dp[0][n] = 1.0;
        for(int i=0;i<n;i++){
            vector<vector<double>> next(
                half+1,
                vector<double>(2*n+1,0.0)
            );
            int cnt = balls[i];
            for(int b=0; b <= half; b++){
                for(int diff = 0; diff <= 2*n; diff++){
                    if(dp[b][diff] == 0){
                        continue;
                    }
                    for(int k=0;k<=cnt;k++){
                        int newBalls = b+k;
                        if(newBalls > half){
                            continue;
                        }
                        int newDiff = diff;
                        if(k>0){
                            newDiff++;
                        }
                        if(cnt-k>0){
                            newDiff--;
                        }
                        double ways = 1.0;
                        for(int j=1;j<=k;j++){
                            ways *= (cnt-j+1);
                            ways /= j;
                        }
                        next[newBalls][newDiff] += 
                            dp[b][diff] * ways;
                    }
                }
            }
            dp = next;
        }
        double good = dp[half][n];
        double totalWays = 1.0;
        for(int i=1; i<= half; i++){
            totalWays *= (total-i+1);
            totalWays /= i;
        }
        return good/totalWays;
    }
};