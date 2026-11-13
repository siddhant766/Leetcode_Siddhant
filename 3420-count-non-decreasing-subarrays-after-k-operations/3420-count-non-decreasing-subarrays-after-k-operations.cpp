class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        
        // Monotonic non-increasing deque storing {value, count}
        // Represents the running maximum blocks from right to left
        deque<pair<int, int>> dq;
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            int count = 1;
            while (!dq.empty() && dq.front().first <= nums[l]) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                ops += 1LL * (nums[l] - val) * cnt;
                count += cnt;
            }
            dq.push_front({nums[l], count});
            
            while (ops > k) {
                auto& [val, cnt] = dq.back();
                ops -= (val - nums[r]);
                --r;
                if (--cnt == 0) {
                    dq.pop_back();
                }
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};