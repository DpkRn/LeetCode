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
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr) return true;
        if(root->left&&root->right){
            bool l=root->left->val==root->val&&isUnivalTree(root->left);
            bool r=(root->right->val==root->val)&&isUnivalTree(root->right);
            return l&&r;
            
        }
        bool l=true,r=true;
        if(root->left) l=(root->left->val==root->val)&&isUnivalTree(root->left);
        if(root->right) r=(root->right->val==root->val)&&isUnivalTree(root->right);
        return l&&r;
    }
};