class Solution {
public:
    vector<vector<int>> ans;
    void fn(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> p;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                p.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(p);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        fn(root);
        return ans;
    }
};