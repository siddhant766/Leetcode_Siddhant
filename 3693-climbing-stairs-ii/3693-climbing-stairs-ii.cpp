#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j] stores the minimum cost to reach step j
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; ++j) {
            long long stepCost = costs[j - 1];

            // Jump from j - 1 (cost: dp[j-1] + 1^2)
            if (dp[j - 1] != LLONG_MAX) {
                dp[j] = min(dp[j], dp[j - 1] + 1 + stepCost);
            }
            // Jump from j - 2 (cost: dp[j-2] + 2^2)
            if (j >= 2 && dp[j - 2] != LLONG_MAX) {
                dp[j] = min(dp[j], dp[j - 2] + 4 + stepCost);
            }
            // Jump from j - 3 (cost: dp[j-3] + 3^2)
            if (j >= 3 && dp[j - 3] != LLONG_MAX) {
                dp[j] = min(dp[j], dp[j - 3] + 9 + stepCost);
            }
        }

        return dp[n];
    }
};