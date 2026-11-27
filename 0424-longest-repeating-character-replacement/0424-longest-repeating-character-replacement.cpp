class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = INT_MIN;
        int n=s.length();
        int l=0;
        vector<int> m(26,0);
        int max_f= 0;
        int w_size =0;
        for(int r=0;r<n;r++){
            m[s[r]-'A']++;
            max_f=max(max_f,m[s[r]-'A']);
            w_size = r-l+1;
            if(w_size-max_f>k){
                m[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};