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
    TreeNode* dummy=new TreeNode(-1); 
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        dummy->right=root;
        root->left=NULL;
        dummy=dummy->right;
        solve(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {  
        TreeNode* original=dummy;
        solve(root);
        return original->right;
    }
};