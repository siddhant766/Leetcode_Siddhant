#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // Case 1: The string is already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case 2: String has length 2 and is unsorted. 
        // Since we can't select the full string, sorting is impossible.
        if (n == 2) {
            return -1;
        }
        
        // Find the absolute minimum and maximum characters in the entire string
        char min_c = s[0];
        char max_c = s[0];
        for (char c : s) {
            min_c = std::min(min_c, c);
            max_c = std::max(max_c, c);
        }
        
        // Case 3: One operation is enough if:
        // - The minimum character is already at index 0 (sort the remaining suffix)
        // - Or the maximum character is already at the last index (sort the prefix)
        if (s[0] == min_c || s[n - 1] == max_c) {
            return 1;
        }
        
        // Case 4: Check if any occurrence of min_c or max_c falls in the inner substring.
        // If it does, we can sort a window surrounding it to move it to the edge in 2 steps.
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_c || s[i] == max_c) {
                return 2;
            }
        }
        
        // Case 5: Worst-case scenario. 
        // If min_c is exclusively at the end and max_c is exclusively at the front, it requires 3 operations.
        return 3;
    }
};
