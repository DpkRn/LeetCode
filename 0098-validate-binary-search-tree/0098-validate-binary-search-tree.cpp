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
    bool solve(TreeNode* root,long long l,long long h){
        
        if(root==NULL) return true;
        if(root->val<=l||root->val>=h) return false;
        
        bool left=solve(root->left,l,root->val);
        bool right=solve(root->right,root->val,h);
       
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-1e12,1e12);
    }
};