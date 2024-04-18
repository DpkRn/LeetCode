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
    bool solve(TreeNode* root, int targetSum,int sum){
        if(!root) return false;
        sum+=root->val;
        if(root->right&&root->left) return solve(root->left,targetSum,sum)||solve(root->right,targetSum,sum);
        if(root->left) return solve(root->left,targetSum,sum);
        if(root->right) return solve(root->right,targetSum,sum);
        return sum==targetSum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};