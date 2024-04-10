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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0,ans=1,maxSum=-1e9;
        while(!q.empty()){
            int size=q.size();
            int currSum=0;
            lvl++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                currSum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currSum>maxSum) {
                ans=lvl;
                maxSum=currSum;
            }
        }
        return ans;
    }
};