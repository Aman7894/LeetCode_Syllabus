class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[r]=nums[i];
                r++;
            }
        }
        while(r<nums.size()){
            nums[r]=0;
            r++;
        }
        
        
    }
};