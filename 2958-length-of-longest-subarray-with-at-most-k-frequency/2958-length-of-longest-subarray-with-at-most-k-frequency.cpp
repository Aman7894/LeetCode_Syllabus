class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int l=0,maxi=0;
        for(int r=0;r<n;r++){
            m[nums[r]]++;
            while(m[nums[r]]>k){
                m[nums[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};