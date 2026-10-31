#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // dp[i][j][0] = entered (i, j) moving DOWN
        // dp[i][j][1] = entered (i, j) moving RIGHT
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

        // Base case at (0, 0)
        dp[0][0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                // 1. Move DOWN from (i - 1, j) into (i, j)
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                    } else {
                        // Reflected down only if entering (i - 1, j) moving right
                        dp[i][j][0] = dp[i - 1][j][1];
                    }
                }

                // 2. Move RIGHT from (i, j - 1) into (i, j)
                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                    } else {
                        // Reflected right only if entering (i, j - 1) moving down
                        dp[i][j][1] = dp[i][j - 1][0];
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};