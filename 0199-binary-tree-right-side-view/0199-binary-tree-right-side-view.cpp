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
    vector<int> rightSideView(TreeNode* root) {
        int last=-1;
        vector<int> ans;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node){
                last=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }else{
                 ans.push_back(last);
                if(!q.empty()){    
                    q.push(nullptr);
                }
            }
            
        }
        return ans;
    }
};