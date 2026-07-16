class Solution {
public:
    long long helper(vector<int>& piles, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;   // ceil(pile/k)
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = helper(piles, mid);

            if (hours <= h) {
                ans = mid;        // mid works, try smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;    // mid too slow
            }
        }

        return ans;
    }
};