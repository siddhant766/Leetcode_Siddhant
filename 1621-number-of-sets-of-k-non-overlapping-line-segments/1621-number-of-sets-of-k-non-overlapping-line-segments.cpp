#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9+7;
        int total = n + k -1;
        int m = 2 * k;
        vector<int> dp(m+1,0);
        dp[0] = 1;
        for(int i=1;i<=total; ++i){
            for(int j=min(i,m); j>= 1; --j){
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        return dp[m];
    }
};