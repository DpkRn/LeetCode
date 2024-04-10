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
#define ll long long
class Solution {
public:
    void solve(TreeNode* root,int targetSum,ll &sum,map<ll,ll> &mp,ll &cnt){
        if(!root) return;
        sum+=root->val;
        cnt+=mp[sum-targetSum];
        mp[sum]++;
        solve(root->left,targetSum,sum,mp,cnt);
        solve(root->right,targetSum,sum,mp,cnt);
        mp[sum]--; sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map<ll,ll> mp;
        mp[0]=1;
        ll sum=0;
        ll cnt=0;
        solve(root,targetSum,sum,mp,cnt);
        return cnt;
    }
};