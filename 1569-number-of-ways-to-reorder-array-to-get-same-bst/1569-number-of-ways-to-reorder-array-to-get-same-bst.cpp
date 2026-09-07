#include <vector>

class Solution {
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> comb;

    long long dfs(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        int root = nums[0];
        std::vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        return comb[n - 1][left.size()] % MOD * left_ways % MOD * right_ways % MOD;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, std::vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }    

        return (dfs(nums) - 1 + MOD) % MOD;  
    }
};