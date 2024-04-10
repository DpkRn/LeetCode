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
    int sum=0;
    void solve(TreeNode* root,string &str){
        if(!root) return;
        if(!root->left&&!root->right){
         str+=root->val+'0';
         sum+=stoi(str,0,2);
         str.pop_back();
            return ;
        }
        str+=root->val+'0';
        solve(root->left,str);
        solve(root->right,str);
        str.pop_back();
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        string str="";
        solve(root,str);
        return sum;
    }
};