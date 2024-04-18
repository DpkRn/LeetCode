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
    void solve(TreeNode* root, int targetSum,vector<int> path,int sum,vector<vector<int>> &ans){
        if(!root) return;
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetSum) ans.push_back(path);
            return ;
        }
        solve(root->left,targetSum,path,sum,ans);
        solve(root->right,targetSum,path,sum,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum=0;
        solve(root,targetSum,path,sum,ans);
        return ans;
    }
};