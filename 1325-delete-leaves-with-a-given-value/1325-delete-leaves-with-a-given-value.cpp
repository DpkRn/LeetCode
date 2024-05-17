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
    TreeNode* dfs(TreeNode* root, int target){
        if(!root) return root;
        root->left=dfs(root->left,target);
        root->right=dfs(root->right,target);
        if (!root->left && !root->right && root->val==target) {
            //delete root;
            return nullptr;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
};