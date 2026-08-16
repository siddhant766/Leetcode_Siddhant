class Solution {
public:
    string convertToTitle(int columnNumber) {
          string result = "";

        while (columnNumber > 0) {
            columnNumber--;  // Handle Excel's 1-based indexing

            char ch = 'A' + (columnNumber % 26);
            result += ch;

            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};