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
//moris traversal O(N) O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*  curr=root;
        vector<int> inorder;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* ryt=curr->left;
                while(ryt->right!=NULL) ryt=ryt->right;
                ryt->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return inorder;
    }
};
/*
//using recursion O(N) O(N)
class Solution {
    vector<int> ans;
public:
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       solve(root);
       return ans;
    }
};
*/