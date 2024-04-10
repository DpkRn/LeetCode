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
    bool ans=true;
    int solve(TreeNode* root){
        if(!root) return 1;
        int l=solve(root->left);
        int r=solve(root->right);
        ans=ans&&(abs(l-r)<=1);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        solve(root);
        return ans;
    }
};
/*
pair<int,int> solve(TreeNode* root){
        if(!root) return {0,1};
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);
        pair<int,int> ans;
        ans.first=max(l.first,r.first)+1;
        ans.second=l.second&&r.second&&abs(l.first-r.first)<=1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return solve(root).second;
        
    }
};
*/