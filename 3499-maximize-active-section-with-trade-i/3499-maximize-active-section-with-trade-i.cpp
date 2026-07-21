class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";
        int m = t.size();

        int ans = ones;

        for (int i = 1; i < m - 1;) {

            if (t[i] == '0') {
                i++;
                continue;
            }

            int j = i;
            while (j < m && t[j] == '1') j++;

            // block [i ... j-1] of 1's
            if (t[i - 1] == '0' && t[j] == '0') {

                int leftZero = 0;
                int p = i - 1;
                while (p >= 0 && t[p] == '0') {
                    leftZero++;
                    p--;
                }

                int rightZero = 0;
                p = j;
                while (p < m && t[p] == '0') {
                    rightZero++;
                    p++;
                }

                int oneLen = j - i;

                // remove one block, then activate merged zero block
                int cur = ones - oneLen + leftZero + oneLen + rightZero;

                ans = max(ans, cur);
            }

            i = j;
        }

        return ans;
    }
};