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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int left=rangeSumBST(root->left,low,high);
        int right=rangeSumBST(root->right,low,high);
        if(low<=root->val&&root->val<=high)
            return left+right+root->val;
        else return left+right;
    }
};
/*
class Solution {
public:
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int left=0,right=0;
        if(root->val>=low){
            left=rangeSumBST(root->left,low,high);
        }
        if(root->val<=high){
            right=rangeSumBST(root->right,low,high);
        }
        if(root->val>=low&&root->val<=high) return root->val+left+right;
        else return left+right;
        
    }
};
*/