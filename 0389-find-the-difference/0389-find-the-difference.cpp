class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        for(char c:t){
            freq[c]--;
        }
        // char ans='\0';
        for(auto it:freq){
            if(it.second <0){
                // ans = it.first;
                return it.first;
            }
        }
        return '\0';
    }
};