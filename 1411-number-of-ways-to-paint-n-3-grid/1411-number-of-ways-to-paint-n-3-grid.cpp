class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long aba = 6;
        long long abc = 6;
        for(int i=2;i<=n;i++){
            long long newABA = (3 * aba + 2 *abc)%MOD;
            long long newABC = (2 * aba + 2 *abc)%MOD;
            aba = newABA;
            abc = newABC;
        }
        return (aba + abc) % MOD;
    }
};