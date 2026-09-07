#include <unordered_map>
#include <algorithm>

class Solution {
    std::unordered_map<int, int> memo;

public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];

        int option2 = n % 2 + 1 + minDays(n / 2);
        int option3 = n % 3 + 1 + minDays(n / 3);
        
        return memo[n] = std::min(option2, option3);
    }
};