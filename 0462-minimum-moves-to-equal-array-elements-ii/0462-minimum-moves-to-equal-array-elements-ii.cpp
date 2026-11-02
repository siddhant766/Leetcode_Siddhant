class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        
        long long moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        return moves;
    }
};