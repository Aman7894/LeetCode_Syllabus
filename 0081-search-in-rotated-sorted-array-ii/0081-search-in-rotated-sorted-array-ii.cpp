class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> st(nums.begin(), nums.end());

        vector<int> arr(st.begin(), st.end());

        int s = 0, e = arr.size() - 1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (arr[m] == target)
                return true;

            if (arr[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }

        return false;
    }
};