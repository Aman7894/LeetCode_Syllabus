class Solution {
public:
    

    bool solve(int i, int j, string &s, string &p,vector<vector<int>>& dp) {

        // Both strings finished
        if (i == s.size() && j == p.size())
            return true;

        // Pattern finished but string left
        if (j == p.size())
            return false;

        // String finished
        if (i == s.size()) {
            while (j < p.size()) {
                if (p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Character matches or '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i + 1, j + 1, s, p,dp);

        // '*'
        if (p[j] == '*') {
            // Match 0 characters OR match 1 character
            return dp[i][j] =
                solve(i, j + 1, s, p,dp) || solve(i + 1, j, s, p,dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p,dp);
    }
};