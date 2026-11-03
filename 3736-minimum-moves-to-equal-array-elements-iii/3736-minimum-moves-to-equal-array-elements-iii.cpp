class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int totalMoves = 0;
        
        for (int num : nums) {
            totalMoves += (maxVal - num);
        }
        
        return totalMoves;
    }
};