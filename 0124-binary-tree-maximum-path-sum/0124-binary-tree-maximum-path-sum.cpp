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
    int maxi=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        maxi=max({maxi,l+root->val,r+root->val,l+r+root->val});
        if(l+root->val<0&&r+root->val<0) return 0;
        else
        return max(l+root->val,r+root->val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};