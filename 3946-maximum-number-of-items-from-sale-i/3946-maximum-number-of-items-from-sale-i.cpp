class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAX_F = 1500;
        int n = static_cast<int>(items.size());

        vector<int> freq(MAX_F + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> multiplesCount(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            for (int m = f; m <= MAX_F; m += f) {
                multiplesCount[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            int p = items[i][1];

            
            int firstGain = multiplesCount[f];

            vector<int> nextDp = dp;

            for (int b = p; b <= budget; ++b) {
                nextDp[b] = max(nextDp[b], dp[b - p] + firstGain);
            }

           
            for (int b = p; b <= budget; ++b) {
                nextDp[b] = max(nextDp[b], nextDp[b - p] + 1);
            }

            dp.swap(nextDp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
