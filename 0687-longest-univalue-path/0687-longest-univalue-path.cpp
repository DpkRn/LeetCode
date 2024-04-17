class Solution {
public:
   pair<int,int> solve(TreeNode* root,int &maxi){
    if(!root) return {0,1001};
    if(root->left==NULL&&root->right==NULL) return {0,root->val};
    pair<int,int> left=solve(root->left,maxi);
    pair<int,int> right=solve(root->right,maxi);
    pair<int,int> temp;
    int len1=root->val==left.second?left.first+1:0;
    int len2=root->val==right.second?right.first+1:0;
       int len3=0;
    if(root->val==left.second&&root->val==right.second){
        len3=len1+len2;
    }
       maxi=max({len1,len2,len3,maxi});
    temp.first=max({len1,len2});
    temp.second=root->val;
    return temp;
   }
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        if(root==NULL) return 0;
        solve(root,maxi);
        return maxi;
    }
};
