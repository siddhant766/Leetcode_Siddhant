#include<vector>
#include<string>
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words[0].size();
        int MOD = 1e9 + 7;
        vector<vector<int>> count(n,vector<int>(26,0));
        for(const string& w: words){
            for(int j =0;j<n;++j){
                count[j][w[j] - 'a']++;
            }
        }
        vector<long long> dp(m+1,0);
        dp[0] = 1;
        for(int j=0;j<n;++j){
            for(int i=m;i>=1;--i){
                char ch = target[i-1];
                dp[i] = (dp[i] + dp[i-1] * count[j][ch-'a']) % MOD;
            }
        }
        return dp[m];
    }
};