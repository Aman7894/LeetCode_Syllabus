class Solution {
public:
    int maxProfit(vector<int>& prices) {
        pair<int, int> s = {prices[0], 0};
        int n = prices.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] < s.first) {
                s = {prices[i], i};
            }
            if (i > s.second) {
                maxi = max(maxi, prices[i] - s.first);
            }
        }

        return maxi;
    }
};