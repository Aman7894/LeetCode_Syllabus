class Solution {
public:
    // Merge sort that counts pairs where left[i] < right[j]
    long long mergeCount(vector<int>& arr, int left, int right) {
        if (right - left <= 1) return 0;

        int mid = (left + right) / 2;
        long long count = 0;

        count += mergeCount(arr, left, mid);
        count += mergeCount(arr, mid, right);

        // Count cross pairs: prefix[i] < prefix[j]
        // where i is in left half, j is in right half
        int j = mid;
        for (int i = left; i < mid; i++) {
            while (j < right && arr[i] >= arr[j]) j++;
            count += (right - j); // all elements from j to right are > arr[i]
        }

        // Standard merge to sort
        inplace_merge(arr.begin() + left, arr.begin() + mid, arr.begin() + right);

        return count;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Build prefix sum array with +1/-1 transform
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        // Count pairs (i < j) where prefix[i] < prefix[j]
        return mergeCount(prefix, 0, n + 1);
    }
};