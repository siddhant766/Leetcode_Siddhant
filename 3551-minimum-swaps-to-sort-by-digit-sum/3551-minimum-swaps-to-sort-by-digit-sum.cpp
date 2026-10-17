#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) { // Changed function name to match the LeetCode judge
        int n = nums.size();
        
        struct Element {
            int val;
            int origIdx;
            int digitSum;
        };
        
        std::vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i, getDigitSum(nums[i])};
        }
        
        std::sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });
        
        std::vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].origIdx == i) {
                continue;
            }
            
            int cycle_size = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].origIdx;
                cycle_size++;
            }
            
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};
