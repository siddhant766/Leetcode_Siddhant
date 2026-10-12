class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bit_counts(31, 0);
        
        for (int x : nums) {
            for (int b = 0; b < 31; ++b) {
                if ((x >> b) & 1) {
                    bit_counts[b]++;
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int b = 0; b < 31; ++b) {
                if (bit_counts[b] > 0) {
                    val |= (1LL << b);
                    bit_counts[b]--;
                }
            }
            ans = (ans + val * val) % MOD;
        }
        
        return ans;
    }
};