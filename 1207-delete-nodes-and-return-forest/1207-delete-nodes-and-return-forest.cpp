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
    vector<int> mp;
    void dfs(TreeNode* &node,vector<TreeNode*> &ans){
        if(node==NULL) return;
        dfs(node->left,ans);
        dfs(node->right,ans);
        if(mp[node->val]==1){
            if(node->left!=NULL) ans.push_back(node->left);
            if(node->right!=NULL) ans.push_back(node->right);
            mp[node->val]=0;
             node=NULL; 
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        mp.resize(1001,0);
        for(int i=0;i<to_delete.size();i++) mp[to_delete[i]]=1;
        vector<TreeNode*> ans;
        dfs(root,ans);
        if(root!=NULL&&mp[root->val]==0) ans.push_back(root);
        return ans;
    }
};