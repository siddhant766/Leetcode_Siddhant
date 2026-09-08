#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();

        vector<int> dp(n + 1, 0);
        vector<int> diff(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            diff[i + 1] = diff[i] + (boxes[i][0] != boxes[i - 1][0]);
        }

        deque<int> dq;
        dq.push_back(0);

        long long current_weight = 0;
        int l = 0;

        for (int i = 1; i <= n; ++i) {
            current_weight += boxes[i - 1][1];

            while (i - l > maxBoxes || current_weight > maxWeight) {
                current_weight -= boxes[l][1];
                l++;
            }

            while (!dq.empty() && dq.front() < l) {
                dq.pop_front();
            }

            dp[i] = dp[dq.front()] - diff[dq.front() + 1] + diff[i] + 2;

            if (i < n) {
                while (!dq.empty()) {
                    int prev = dq.back();
                    if (dp[prev] - diff[prev + 1] >= dp[i] - diff[i + 1]) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back(i);
            }
        }

        return dp[n];
    }
};