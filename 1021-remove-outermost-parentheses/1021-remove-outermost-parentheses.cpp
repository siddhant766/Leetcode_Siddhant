class Solution {
public:
    string removeOuterParentheses(string s) {
         string ans = "";
         int dept = 0;
         for(char c:s){
            if( c == '('){
                if(dept>0){
                    ans += c;
                }
                dept++;
            }else{
                dept--;
                if(dept>0){
                    ans +=c;
                }
            }
         }
         return ans;
    }
};