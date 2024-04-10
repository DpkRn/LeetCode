/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(target==original) return cloned;
        TreeNode* left=getTargetCopy(original->left,cloned->left,target);
        TreeNode* right=getTargetCopy(original->right,cloned->right,target);
        if(!left&&!right) return NULL;
        if(!left&&right) return right;
        if(!right&&left) return left;
        else return NULL;
       
    }
};