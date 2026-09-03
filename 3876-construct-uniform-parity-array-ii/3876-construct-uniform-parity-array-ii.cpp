class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool even = false;
        bool odd = false;

        int minEven = INT_MAX;
        int minOdd = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                even = true;
                minEven = min(minEven, nums1[i]);
            }
            else {
                odd = true;
                minOdd = min(minOdd, nums1[i]);
            }
        }

        // Already all even or all odd
        if (!even || !odd) {
            return true;
        }

        // Smallest odd must be smaller than every even number
        if (minOdd < minEven) {
            return true;
        }

        return false;
    }
};