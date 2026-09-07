#include<vector>
#include<cmath>
#include<cstring>
class Solution {
    int memo[101][201];
    const int MOD = 1e9 + 7;
    int solve(const std::vector<int>& locations, int curr, int finish, int fuel){
        if(memo[curr][fuel] != -1)return memo[curr][fuel];
        int ans = (curr == finish) ? 1 : 0;
        for(int next = 0; next < locations.size(); ++next){
            if(next != curr){
                int cost = std::abs(locations[curr] - locations[next]);
                if(fuel >= cost ){
                    ans = (ans + solve(locations, next, finish, fuel - cost)) % MOD;
                }
            }
        }
        return memo[curr][fuel] = ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        std::memset(memo, -1, sizeof(memo));
        return solve(locations,start,finish,fuel);
    }
};