class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n+1,0);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                continue;
            }
            long long num = 0;
            for(int j=i;j<n;j++){
                num = num * 10+(s[j] - '0');
                if(num>k){
                    break;
                }
                dp[i] = (dp[i] + dp[j+1] )% MOD;
            }
        }
        return dp[0];
    }
};