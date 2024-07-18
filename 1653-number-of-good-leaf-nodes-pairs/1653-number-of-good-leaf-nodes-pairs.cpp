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
    void dfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& mp, int dis, int& ans, int k, unordered_map<TreeNode*, bool>& vis) {
        vis[root] = true;
        if (root->left==NULL && root->right ==NULL && dis <= k && dis != 0) {
            ans++;
        }
        for (auto it : mp[root]) {
            if (!vis[it]) {
                dfs(it, mp, dis + 1, ans, k, vis);
            }
        }
    }

    void fillmap(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& mp, unordered_map<TreeNode*, bool>& vis) {
        if (root == nullptr) {
            return;
        }
        vis[root] = false;
        if (root->left) {
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
        }
        if (root->right) {
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
        }
        fillmap(root->left, mp, vis);
        fillmap(root->right, mp, vis);
    }

    void resetVisited(unordered_map<TreeNode*, bool>& vis) {
        for (auto& entry : vis) {
            entry.second = false;
        }
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        unordered_map<TreeNode*, bool> vis;
        int ans = 0;
        fillmap(root, mp, vis);
        for (auto it : mp) {
            if (it.first->left==NULL && it.first->right ==NULL) { 
                dfs(it.first, mp, 0, ans, distance, vis);
                resetVisited(vis);  
            }
        }
        return ans / 2; 
    }
};