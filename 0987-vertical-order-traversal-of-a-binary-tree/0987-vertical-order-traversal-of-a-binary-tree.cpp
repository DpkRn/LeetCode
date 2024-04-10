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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                pq.push({c,r,node->val});
                q.pop();
              
                if(node->left) {
                    q.push({node->left,{r+1,c-1}});
                   
                }
                if(node->right){
                    q.push({node->right,{r+1,c+1}});
                   
                } 
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> temp;
            int c=pq.top()[0];
            while(!pq.empty()&&pq.top()[0]==c){
                cout<<pq.top()[2]<<" ";
                temp.push_back(pq.top()[2]);
                pq.pop();
            }
            cout<<",";
            ans.push_back(temp);   
        }
        
        return ans;
        
    }
};