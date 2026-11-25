#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD = 1000000000000000003ULL; // Large 64-bit prime
        const uint64_t BASE = 1315423911ULL;

        // Precompute powers and prefix hashes
        vector<uint64_t> power(n + 1, 1), pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            power[i + 1] = (__int128)power[i] * BASE % MOD;
            pref[i + 1] = ((__int128)pref[i] * BASE + nums[i]) % MOD;
        }

        // Check if any subarray of length `len` is unique
        auto hasUnique = [&](int len) -> bool {
            vector<uint64_t> hashes;
            hashes.reserve(n - len + 1);

            for (int i = 0; i + len <= n; ++i) {
                uint64_t subHash = (pref[i + len] + MOD - ((__int128)pref[i] * power[len] % MOD)) % MOD;
                hashes.push_back(subHash);
            }

            // Sorting numbers is O(N log N) instead of O(N^2 log N)
            sort(hashes.begin(), hashes.end());

            for (int i = 0; i < (int)hashes.size(); ++i) {
                bool sameLeft = (i > 0) && (hashes[i] == hashes[i - 1]);
                bool sameRight = (i + 1 < (int)hashes.size()) && (hashes[i] == hashes[i + 1]);
                if (!sameLeft && !sameRight) return true;
            }
            return false;
        };

        // Binary search for the smallest valid length
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};