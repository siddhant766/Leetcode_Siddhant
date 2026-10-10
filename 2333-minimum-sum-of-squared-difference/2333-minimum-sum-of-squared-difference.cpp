#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int max_diff = 0;
        
        // Step 1: Count frequencies of each absolute difference
        // Constraints state max element value is 10^5, so max difference is 10^5
        std::vector<long long> bucket(100001, 0);
        
        for (size_t i = 0; i < nums1.size(); ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                bucket[diff]++;
                max_diff = std::max(max_diff, diff);
            }
        }
        
        // Step 2: Greedily reduce the largest differences down to smaller buckets
        for (int d = max_diff; d > 0 && k > 0; --d) {
            if (bucket[d] == 0) continue;
            
            // Determine how many elements we can shift from bucket[d] to bucket[d - 1]
            long long take = std::min(k, bucket[d]);
            bucket[d] -= take;
            bucket[d - 1] += take;
            k -= take;
        }
        
        // Step 3: Calculate the final sum of squared differences
        long long min_squared_sum = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (bucket[d] > 0) {
                min_squared_sum += (d * d) * bucket[d];
            }
        }
        
        return min_squared_sum;
    }
};
