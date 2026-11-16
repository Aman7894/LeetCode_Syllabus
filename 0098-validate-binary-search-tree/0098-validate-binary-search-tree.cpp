/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fn(TreeNode* root , long long left , long long right){
        if(!root) return true;
        if(root->val<=left || root->val>=right) return false;

       return fn(root->left,left,root->val) &&
        fn(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return fn(root,LLONG_MIN,LLONG_MAX);
        
    }
};