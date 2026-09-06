class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();
        vector<int> height(n,0);
        int ans = 0;
        for( int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                height[j] = mat[i][j] ? height[j] +1 : 0;
            }
            for(int j=0;j<n;j++){
                int h = height[j];
                for(int k=j;k>=0 && height[k]; k--){
                    h = min(h,height[k]);
                    ans += h;
                }
            }
        }
        return ans;
    }
};