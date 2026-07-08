class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        long long sum;
        int cnt;
    };

    vector<Node> tree;
    vector<long long> pow10;
    string s;

    Node merge(Node left, Node right) {
        Node res;
        res.cnt = left.cnt + right.cnt;
        res.sum = left.sum + right.sum;
        res.val = (left.val * pow10[right.cnt] + right.val) % MOD;
        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            if (s[l] == '0') {
                tree[idx] = {0, 0, 0};
            } else {
                int d = s[l] - '0';
                tree[idx] = {d, d, 1};
            }
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return {0, 0, 0};

        if (ql <= l && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        int n = s.size();

        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};