#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Two large prime moduli and bases to prevent hash collisions
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 1315423911ULL % MOD1;
        const uint64_t BASE2 = 2654435761ULL % MOD2;

        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<uint64_t> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2;
            pref1[i + 1] = (pref1[i] * BASE1 + nums[i]) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto hasUniqueSubarray = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);

            for (int i = 0; i + len <= n; ++i) {
                uint64_t h1 = (pref1[i + len] + MOD1 - (pref1[i] * pow1[len]) % MOD1) % MOD1;
                uint64_t h2 = (pref2[i + len] + MOD2 - (pref2[i] * pow2[len]) % MOD2) % MOD2;
                uint64_t combinedHash = (h1 << 32) | h2;
                freq[combinedHash]++;
            }

            for (const auto& [hash, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUniqueSubarray(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};