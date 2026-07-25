class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;
        int temp = n;
        while(temp !=0){
            int x = temp % 10;
            num.push_back(x);
            temp = temp/10;
        }
        sort(num.begin(),num.end());
        reverse(num.begin(),num.end());
        int ans = num[0]*num[1];
        return ans;
    }
};