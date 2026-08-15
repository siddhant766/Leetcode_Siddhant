class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sit = 0;

        for(int x:nums){
            sit ^= x;
        }
        if(sit != 0){
            return nums.size();
        }
        for(int n : nums){
            if(n != 0){
                return nums.size()-1;
            }
        }


        return 0;
    }
};