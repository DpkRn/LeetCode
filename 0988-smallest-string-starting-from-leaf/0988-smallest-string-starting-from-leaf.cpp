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
    void solve(TreeNode* root,string path,string &str){
        if(root==NULL) return ;
        path=(char)('a'+root->val)+path;
        if(!root->left&&!root->right){
            str=min(str,path);
            return;
        }
        solve(root->left,path,str);
        solve(root->right,path,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        string str="~";
        string path="";
        solve(root,path,str);
        return str;
    }
};