class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1,0);
        for(int x:nums){
            count[x]++;
        }
        int duplicate = -1;
        int missing = -1;
        for(int i=0;i<=n;i++){
            if(count[i] == 2){
                duplicate = i;
            }
            else if(count[i] == 0){
                missing = i;
            }
        }
        vector<int> ans;
        ans.push_back(duplicate);
        ans.push_back(missing);
        return ans;
    }
};