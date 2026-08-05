class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(nums[i]);  
            }
        }
       
        sort(ans.begin(),ans.end());
        for(int i:nums){
            if(i%2!=0)
            ans.push_back(i);
        }  
         return ans;


    }
};