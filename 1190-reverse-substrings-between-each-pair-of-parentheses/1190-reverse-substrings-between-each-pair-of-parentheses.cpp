class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> p;
        string q;

        for (char c : s) {
            if (c == '(') {
                p.push(q.size());
            } else if (c == ')') {
                int start = p.top();
                p.pop();
                reverse(q.begin() + start, q.end());
            } else {
                q += c;
            }
        }

        return q;
    }
};