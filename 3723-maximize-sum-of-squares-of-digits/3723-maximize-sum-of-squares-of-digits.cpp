#include <string>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        // A number with 'num' digits can have a maximum digit sum of 9 * num.
        if (sum > 9LL * num) {
            return "";
        }

        std::string ans;
        ans.reserve(num);

        int nines = sum / 9;
        int rem = sum % 9;

        // Place as many 9s as possible to maximize sum of squares
        ans.append(nines, '9');

        // Place the leftover non-zero remainder
        if (rem > 0) {
            ans.push_back('0' + rem);
        }

        // Pad the rest with 0s to reach exactly 'num' digits
        if (static_cast<int>(ans.size()) < num) {
            ans.append(num - ans.size(), '0');
        }

        return ans;
    }
};