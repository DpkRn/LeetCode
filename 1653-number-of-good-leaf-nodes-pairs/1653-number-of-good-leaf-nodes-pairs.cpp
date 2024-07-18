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
int cnt=0;
    vector<int> dfs(TreeNode* root,int d){
        if(!root->left&&!root->right) return {1};
        vector<int> left,right;
        if(root->left) left=dfs(root->left,d);
        if(root->right) right=dfs(root->right,d);
        vector<int> temp;
        for(auto itLeft:left){
            
            for(auto itRight:right){
                if(itLeft+itRight<=d) cnt++;
            }
        } 
        for(auto itLeft:left) if(itLeft+1<=d)  temp.push_back(itLeft+1);
        for(auto itRight:right) if(itRight+1<=d) temp.push_back(itRight+1);
        return temp;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return cnt;
    }
};