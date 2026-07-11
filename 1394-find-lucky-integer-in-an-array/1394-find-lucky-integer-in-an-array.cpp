class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i:arr){
            freq[i]++;
        }
        vector<int> ans;
        for(auto& it:freq){
            if(it.first==it.second){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return (n==0)?-1:ans[n-1];
    }
};