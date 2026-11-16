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
    vector<TreeNode*> solve(int s,int e){
        if(s>e){
            return {NULL};
        }
        if(s==e){
            TreeNode* root= new TreeNode(s);
            return {root};
        }
        vector<TreeNode*> result;
        for(int i=s;i<=e;i++){
          vector<TreeNode*> left_bst= solve(s,i-1);
          vector<TreeNode*> right_bst=solve(i+1,e);
          for(TreeNode* left_root:left_bst){
            for(TreeNode* right_root:right_bst){
                TreeNode* root=new TreeNode(i);
                root->left=left_root;
                root->right=right_root;

                result.push_back(root);
            }
          }

        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
       return solve(1,n);

    }
};