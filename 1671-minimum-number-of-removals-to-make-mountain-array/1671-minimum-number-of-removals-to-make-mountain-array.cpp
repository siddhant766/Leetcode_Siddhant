#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n,1);
        vector<int> v;
        for(int i=0; i<n;++i){
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            if( it == v.end()){

                v.push_back(nums[i]);
                inc[i] = v.size();
            }else{
                *it = nums[i];
                inc[i] = it - v.begin() + 1;
            }
        }
        vector<int> dec(n,1);
        v.clear();
        for(int i=n-1; i>= 0; --i){
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            if(it == v.end()){
                v.push_back(nums[i]);
                dec[i] = v.size();
            }else{
                *it = nums[i];
                dec[i] = it - v.begin() +  1;
            }
        }
        int max_len = 0;
        for(int i=1;i<n-1; ++i){
            if(inc[i] > 1 && dec[i] > 1){
                max_len = max(max_len, inc[i] + dec[i] -1);
            }
        }
        return n - max_len;
    }
};