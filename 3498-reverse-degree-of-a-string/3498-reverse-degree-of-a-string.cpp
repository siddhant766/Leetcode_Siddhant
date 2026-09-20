class Solution {
public:
    int reverseDegree(string s) {
         long long total = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Reversed alphabet value: 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            long long char_val = 26 - (s[i] - 'a');
            
            // 1-indexed position in string
            long long str_pos = i + 1;
            
            total += char_val * str_pos;
        }
        
        return total;
    }
};