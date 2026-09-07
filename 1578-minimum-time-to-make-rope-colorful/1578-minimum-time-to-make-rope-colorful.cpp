#include<string>
#include<vector>
#include<algorithm>
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int maxTime = neededTime[0];
        for(int i=1; i< colors.size();++i){
            if(colors[i] == colors[i-1]){
                totalTime += std::min(maxTime, neededTime[i]);
                maxTime = std::max(maxTime,neededTime[i]);
            }else{
                maxTime = neededTime[i];
            }
        }
        return totalTime;
    }
};