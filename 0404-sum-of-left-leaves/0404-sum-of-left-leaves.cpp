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
    int leaf(TreeNode* root){
         if(root==NULL) return 0;
        int l=0,r=0;
        l=leaf(root->left);
        if(!(root->right==NULL||root->right->left==NULL&&root->right->right==NULL)) 
         r=leaf(root->right);
        if(root->left==NULL&&root->right==NULL)
            return l+r+root->val;
        else
            return l+r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return  0;
        if(root->left==NULL&&root->right==NULL) return 0;
       return leaf(root);
    }
};