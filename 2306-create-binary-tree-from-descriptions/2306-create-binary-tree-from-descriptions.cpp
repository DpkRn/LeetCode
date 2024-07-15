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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        // m for creating all nodes and having their reference
        unordered_map<int, TreeNode*> m;
        // When we have connected all the nodes then we will need to find the root
        // So mark every child node as false and the node which will be missing is Root
        unordered_map<int,bool> isRoot;
        // Iterate over all the nodes given
        for (int i = 0; i < d.size(); i++) {
            // Check if the parent node exists or not
            if (m.find(d[i][0]) == m.end()) {
                m[d[i][0]] = new TreeNode(d[i][0]);
            }
            // check if the child node exists
            if (m.find(d[i][1]) == m.end()) {
                m[d[i][1]] = new TreeNode(d[i][1]);
            }
            // Mark all child nodes as false
            isRoot[d[i][1]]=false;
            // Connect child to parent 
            if (d[i][2] == 1) {
                m[d[i][0]]->left=m[d[i][1]];
            }else{
                m[d[i][0]]->right=m[d[i][1]];
            }
        }
        // Now we hae=ve to find the node which is not a child
        TreeNode* root=NULL;
        // IsRoot contains all child nodes and missing will be our root
        for( auto it =m.begin();it!=m.end();it++){
            if(isRoot.find(it->first)==isRoot.end()){
                root=it->second;
                break;
            }
        }
        return root;
    }
};