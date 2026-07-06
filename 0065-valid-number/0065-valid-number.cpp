class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenExp)
                    digitAfterExp = true;
            }
            else if (c == '+' || c == '-') {
                // Sign is valid only at the beginning or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Dot can appear only once and before e/E
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // e/E can appear only once and only after a digit
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                digitAfterExp = false;
            }
            else {
                return false;
            }
        }

        return seenDigit && digitAfterExp;
    }
};