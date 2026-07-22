class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> first, last, freq;

for (int i = 0; i < nums.size(); i++) {
    if (!first.count(nums[i]))
        first[nums[i]] = i;
    last[nums[i]] = i;
    freq[nums[i]]++;
}
      int degree = 0;
for (auto &p : freq)
    degree = max(degree, p.second);

int ans = INT_MAX;

for (auto &p : freq) {
    if (p.second == degree) {
        ans = min(ans, last[p.first] - first[p.first] + 1);
    }
}
    return ans;
    }
};