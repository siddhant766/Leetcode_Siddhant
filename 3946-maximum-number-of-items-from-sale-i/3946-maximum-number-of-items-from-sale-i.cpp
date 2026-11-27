class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int MAX_F = 1500;
        
        // 1. Count frequency of each factor
        vector<int> freq(MAX_F + 1, 0);
        int min_price = INT_MAX;
        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }
        
        // 2. Precompute total items gained on the FIRST purchase of an item with factor f
        // (1 purchased copy + free copies of all j != i where factor[j] % f == 0)
        vector<int> first_buy_gain(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (freq[f] == 0) continue;
            for (int mult = f; mult <= MAX_F; mult += f) {
                first_buy_gain[f] += freq[mult];
            }
        }
        
        // 3. 0/1 Knapsack for the first purchase of each item
        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            int price = item[1];
            int gain = first_buy_gain[f];
            
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }
        
        // 4. Fill any remaining budget with copies of the cheapest item (+1 copy per min_price)
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra_copies = (budget - b) / min_price;
            ans = max(ans, dp[b] + extra_copies);
        }
        
        return ans;
    }
};