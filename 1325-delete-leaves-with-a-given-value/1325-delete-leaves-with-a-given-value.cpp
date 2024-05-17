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
    TreeNode* dfs(TreeNode* root,int target){
        if(root==NULL) return NULL;
        TreeNode* left=dfs(root->left,target);
        TreeNode* right=dfs(root->right,target);
        if(left!=NULL&&left->left==NULL&&left->right==NULL&&left->val==target){
            root->left=NULL;
        }
        if(right!=NULL&&right->left==NULL&&right->right==NULL&&right->val==target){
            root->right=NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       
        TreeNode* ans=dfs(root,target);
        if(ans==NULL) return NULL;
        if(ans->left==NULL&&ans->right==NULL&&ans->val==target) ans=NULL;
        return ans;
    }
};