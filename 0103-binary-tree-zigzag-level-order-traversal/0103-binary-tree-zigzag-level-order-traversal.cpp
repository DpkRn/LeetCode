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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        bool isLeft=true;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;
        q.push(root); q.push(nullptr);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node) {
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }else{
                if(!q.empty()) q.push(nullptr);
                if(!isLeft){
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
                isLeft=!isLeft;
                temp.clear();
            }        
        }
        return ans;
    }
};