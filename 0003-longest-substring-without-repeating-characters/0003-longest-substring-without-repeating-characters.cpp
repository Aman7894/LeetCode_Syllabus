class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int  ans=0;
        for(int i=0;i<n;i++){
            int  len=0;
            unordered_set<int> p;
            for(int j=i;j<n;j++){
                if(p.find(s[j])!=p.end()) break;
                len=j-i+1;
                ans=max(ans,len);
                p.insert(s[j]);
            }
        }
        return ans;
    }
};