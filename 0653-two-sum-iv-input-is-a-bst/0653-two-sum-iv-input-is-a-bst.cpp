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
    map<int,int> mp;
    //mp[0]=1;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        int target=k-root->val;
        if(mp[target]==1) return true;
        mp[root->val]=1;
        if(findTarget(root->left,k)) return true;
        return findTarget(root->right,k);
    }
};