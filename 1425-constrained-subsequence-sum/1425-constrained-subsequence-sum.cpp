class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front() < i-k){
                dq.pop_front();
            }
            if(!dq.empty()){
                dp[i] = nums[i] + max(0,dp[dq.front()]);
            }else{
                dp[i] = nums[i];
            }
            ans = max(ans,dp[i]);
            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans;
    }
};