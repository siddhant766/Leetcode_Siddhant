class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];
        vector<vector<int>> comb(h+v+1, vector<int>(h+v+1,0));
        for(int i=0;i<=h+v;++i){
            comb[i][0] = 1;
            for(int j = 1; j<= i; ++j){
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
        string ans = "";
        while(h>0 && v>0){
            int ways_with_h = comb[h + v - 1][v];
            if( k <= ways_with_h){
                ans += 'H';
                h--;
            }else{
                ans += 'V';
                k -= ways_with_h;
                v--;
            }
        }
        while( h>0){
            ans  += 'H';
            h--;
        }
        while( v>0){
            ans += 'V';
            v--;
        }
        return ans;
    }
};