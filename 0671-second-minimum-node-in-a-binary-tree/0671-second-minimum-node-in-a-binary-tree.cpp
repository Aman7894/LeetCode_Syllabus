class Solution {
public:
    void mini(TreeNode* root, int& ans) {
        if (!root) return;

        ans = min(ans, root->val);

        mini(root->left, ans);
        mini(root->right, ans);
    }

    void second(TreeNode* root, int p, long long& ans) {
        if (!root) return;

        if (root->val > p) {
            ans = min(ans, (long long)root->val);
        }

        second(root->left, p, ans);
        second(root->right, p, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        int p = root->val;
        mini(root, p);

        long long ans = LLONG_MAX;
        second(root, p, ans);

        if (ans == LLONG_MAX)
            return -1;

        return (int)ans;
    }
};