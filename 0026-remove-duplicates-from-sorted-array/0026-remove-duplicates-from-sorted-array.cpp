class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        int idx=0;
        for(int num:nums ){
          if(s.find(num)==0){
            s.insert(num);
            nums[idx++]=num;
          }
        }
        nums.resize(idx);
        return s.size();
    }
};