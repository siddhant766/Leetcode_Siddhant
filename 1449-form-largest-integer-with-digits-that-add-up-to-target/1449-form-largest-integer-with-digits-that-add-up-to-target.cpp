class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "#");
        dp[0] = "";
        for(int t = 1; t <= target; t++ ){
            for( int d = 1; d <= 9 ; d++){
                if( t>= cost[d-1] && dp[t-cost[d-1]] != "#"){
                    string curr = dp[t-cost[d-1]] + char('0' + d);
                    if(dp[t] == "#" || curr.size() > dp[t].size() ||
                        (curr.size() == dp[t].size() && curr > dp[t])){
                            dp[t] = curr;
                        }
                }
            }
        }
        return dp[target]  == "#"?"0":dp[target];
    }
};