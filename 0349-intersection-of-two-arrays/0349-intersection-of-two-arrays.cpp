class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i:nums1){
            m[i]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i])!=m.end()){
                ans.push_back(nums2[i]);
                m.erase(nums2[i]);
            }
        }
        return ans;
    }
};