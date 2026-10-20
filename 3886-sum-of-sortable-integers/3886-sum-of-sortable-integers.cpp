#include <vector>
#include <algorithm>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> s = nums;
        std::sort(s.begin(), s.end());

        // Fast path: if already sorted, every divisor k of n is sortable
        if (nums == s) {
            int all_sum = 0;
            for (int k = 1; k <= n; ++k) {
                if (n % k == 0) {
                    all_sum += k;
                }
            }
            return all_sum;
        }

        // Helper lambda to check if a given divisor k is sortable
        auto isValid = [&](int k) -> bool {
            for (int i = 0; i < n; i += k) {
                int drop_count = 0;
                int drop_idx = 0;

                // Count cyclic drops: nums[i + j] > nums[i + (j + 1) % k]
                for (int j = 0; j < k; ++j) {
                    int cur = nums[i + j];
                    int nxt = nums[i + (j + 1) % k];
                    if (cur > nxt) {
                        drop_count++;
                        drop_idx = (j + 1) % k;
                        if (drop_count > 1) {
                            return false;
                        }
                    }
                }

                // If drop_count is 0, the block is already non-decreasing cyclically
                int start = (drop_count == 0) ? 0 : drop_idx;

                // Check if starting at `start` matches the target sorted segment s[i ... i + k - 1]
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start + j) % k] != s[i + j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        int total_sum = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isValid(k)) {
                    total_sum += k;
                }
            }
        }

        return total_sum;
    }
};