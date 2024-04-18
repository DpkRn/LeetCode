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
    void fun(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        fun(root->left,ans);
        fun(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        fun(root,ans);
        return ans;
    }
};
/*class Solution {
public:
    vector<int> solve(TreeNode* root, vector<int> ans){
        if(root==NULL) return ans;
        ans.push_back(root->val);
        ans=solve(root->left,ans);
        ans=solve(root->right,ans);
        return ans;
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        return solve(root,ans);        
    }
};*/