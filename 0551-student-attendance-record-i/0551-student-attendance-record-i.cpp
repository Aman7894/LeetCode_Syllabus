class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;

        for(char c : s) {
            if(c == 'A') {
                absent++;
                late = 0;
            }
            else if(c == 'L') {
                late++;
            }
            else {
                late = 0;
            }

            if(absent >= 2 || late >= 3)
                return false;
        }

        return true;
    }
};