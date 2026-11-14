#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;

        // Iterate through every possible starting index
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            
            // Expand the subarray to the right
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                int length = j - i + 1;
                
                // Stop expanding if we exceed the maximum allowed length r
                if (length > r) {
                    break;
                }
                
                // Check if length is within [l, r] and sum is strictly positive
                if (length >= l && currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};