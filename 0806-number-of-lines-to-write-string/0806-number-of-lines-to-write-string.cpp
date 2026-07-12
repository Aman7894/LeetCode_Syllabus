class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        unordered_map<char, int> mp;

        char ch = 'a';
        for (int i = 0; i < 26; i++) {
            mp[ch] = widths[i];
            ch++;
        }

        int lines = 1;
        int val = 0;

        for (int i = 0; i < s.length(); i++) {
            if (val + mp[s[i]] <= 100) {
                val += mp[s[i]];
            } else {
                lines++;
                val = mp[s[i]];
            }
        }

        return {lines, val};
    }
};