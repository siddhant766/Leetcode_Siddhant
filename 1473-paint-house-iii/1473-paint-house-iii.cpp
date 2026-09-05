class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;

        vector<vector<int>> dp(
            target + 1,
            vector<int>(n + 1, INF)
        );

        if (houses[0] == 0) {
            for (int c = 1; c <= n; c++)
                dp[1][c] = cost[0][c - 1];
        } else {
            dp[1][houses[0]] = 0;
        }

        for (int i = 1; i < m; i++) {
            vector<vector<int>> next(
                target + 1,
                vector<int>(n + 1, INF)
            );

            for (int groups = 1; groups <= target; groups++) {
                for (int prev = 1; prev <= n; prev++) {
                    if (dp[groups][prev] == INF)
                        continue;

                    for (int cur = 1; cur <= n; cur++) {
                        if (houses[i] != 0 && houses[i] != cur)
                            continue;

                        int ng = groups + (prev != cur);

                        if (ng > target)
                            continue;

                        int paintCost = houses[i] == 0 ? cost[i][cur - 1] : 0;

                        next[ng][cur] = min(
                            next[ng][cur],
                            dp[groups][prev] + paintCost
                        );
                    }
                }
            }

            dp = next;
        }

        int ans = INF;

        for (int c = 1; c <= n; c++) {
            ans = min(ans, dp[target][c]);
        }

        return ans == INF ? -1 : ans;
    }
};