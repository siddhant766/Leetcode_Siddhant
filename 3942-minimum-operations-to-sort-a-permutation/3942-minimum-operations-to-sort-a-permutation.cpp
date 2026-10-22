#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool is_inc = true;
        bool is_dec = true;

        for (int i = 0; i < n; ++i) {
            int next_val_inc = (nums[i] + 1) % n;
            int next_val_dec = (nums[i] - 1 + n) % n;
            int actual_next = nums[(i + 1) % n];

            if (actual_next != next_val_inc) is_inc = false;
            if (actual_next != next_val_dec) is_dec = false;
        }

        if (is_inc) {
            // Option 1: Rotate left p times -> p
            // Option 2: Reverse -> rotate -> reverse -> n - p + 2
            return std::min(p, n - p + 2);
        }

        if (is_dec) {
            // Option 1: Reverse first -> rotate left (n - 1 - p) times -> n - p
            // Option 2: Rotate left (p + 1) % n times -> reverse -> ((p + 1) % n) + 1
            int op1 = n - p;
            int op2 = ((p + 1) % n) + 1;
            return std::min(op1, op2);
        }

        return -1;
    }
};