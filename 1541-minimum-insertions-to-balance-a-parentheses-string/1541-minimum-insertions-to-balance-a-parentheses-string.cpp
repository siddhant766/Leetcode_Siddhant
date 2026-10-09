class Solution {
public:
    int minInsertions(string s) {
         int insertions = 0;
        int open_count = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open_count++;
            } else {
                // Check if the current ')' is followed by another ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Consume the second ')'
                } else {
                    insertions++; // Add a missing ')'
                }

                // Match with a prior '('
                if (open_count > 0) {
                    open_count--;
                } else {
                    insertions++; // Add a missing '('
                }
            }
        }

        // Remaining unmatched '(' each need two ')'
        insertions += open_count * 2;

        return insertions;
    }
    
};