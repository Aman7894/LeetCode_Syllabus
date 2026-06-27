class Solution {
public:
 
    int maximumLength(vector<int>& nums) {
       unordered_map<long long , int> m;
       for(int i:nums){
        m[i]++;
       }
       int ans=1;
       for(auto& [x,cnt]:m){
         if(x==1){
            ans=max(ans,(cnt%2)?cnt:cnt-1);
            continue;
         }
         long long curr=x;
         int len=0;
         while(m[curr]>=2 && m.count(curr * curr)){
            len+=2;
            curr=curr*curr;
         }
         if(m[curr]>=1){
            len+=1;
         }
         ans=max(ans,len);
       }
       return ans;
    }
};