class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp;
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp.rbegin()->first - mp.begin()->first > 2) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }
};