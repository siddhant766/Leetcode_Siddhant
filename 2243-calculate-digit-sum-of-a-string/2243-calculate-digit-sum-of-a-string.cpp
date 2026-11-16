class Solution {
public:
    string digitSum(string s, int k) {
        // Continue performing rounds while the string length exceeds k
        while (s.length() > k) {
            string next_s = "";
            
            // Iterate through s in chunks of size k
            for (int i = 0; i < s.length(); i += k) {
                int group_sum = 0;
                
                // Sum the digits in the current group (handles final group < k automatically)
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    group_sum += s[j] - '0';
                }
                
                // Append the group sum as a string
                next_s += to_string(group_sum);
            }
            
            // Update s for the next round
            s = next_s;
        }
        
        return s;
    }
};