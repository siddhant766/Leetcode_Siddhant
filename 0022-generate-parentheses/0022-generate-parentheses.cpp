#include <vector>
#include <string>

class Solution {
private:
    void backtrack(int n, int open, int close, std::string current, std::vector<std::string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(n, open + 1, close, current + '(', result);
        }

        if (close < open) {
            backtrack(n, open, close + 1, current + ')', result);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};