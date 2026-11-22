class Solution {
public:
 int count(vector<int> &nums, int val) {
    int c = 0;
    for (int i : nums) {
        if (i == val) c++;
    }
    return c;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    set<int> seen;

    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(nums[i])) continue;  
        seen.insert(nums[i]);

        int c = count(nums, nums[i]);
        pq.push({c, nums[i]}); 
    }

    vector<int> ans;
    while (k-- && !pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
};
