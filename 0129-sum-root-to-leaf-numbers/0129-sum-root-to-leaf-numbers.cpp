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
void solve(TreeNode* root,string str,int &sum){
    if(root==NULL) return ;
    if(root->left==NULL&&root->right==NULL){
         str+=to_string(root->val);
         sum+=stoi(str);        
         return;
    }
    str+=to_string(root->val);
    solve(root->left,str,sum);
    solve(root->right,str,sum);
    
}

    int sumNumbers(TreeNode* root) {
        int sum=0;
        string str="";
        solve(root,str,sum);
        return sum;
    }
};