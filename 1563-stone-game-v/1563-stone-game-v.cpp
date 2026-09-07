#include<vector>
#include<numeric>
#include<algorithm>
class Solution {
    int memo[501][501];
    std::vector<int>prefix;
    int solve(int i,int j){
        if(i == j)return 0;
        if(memo[i][j] != -1)return memo[i][j];
        int res = 0;
        int total = prefix[j+1] - prefix[i];

        for(int k=i;k<j;++k){
            int leftSum = prefix[k+1] - prefix[i];
            int rightSum = total - leftSum;
            if(leftSum < rightSum ){
                res = std::max(res,leftSum + solve(i,k));
            }else if(rightSum<leftSum){
                res = std::max(res,rightSum + solve(k+1,j));
            }else{
                res = std::max(res,leftSum + std::max(solve(i,k),solve(k+1,j)));
            }
        }
        return memo[i][j] = res;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.assign(n+1,0);
        for(int i=0;i<n;++i){
            prefix[i+1] = prefix[i] + stoneValue[i];

        }
        std::fill(&memo[0][0] , &memo[0][0] + sizeof(memo)/sizeof(int),-1);
        return solve(0,n-1);
    }
};