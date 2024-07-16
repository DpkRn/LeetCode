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
string startString,endString;
 TreeNode* lca(TreeNode* node,string &pathString,int startValue,int destValue){
    if(!node) return NULL;
    if(node->val==startValue) startString=pathString;
    if(node->val==destValue)  endString=pathString;
    pathString+='L';
    TreeNode* l=lca(node->left,pathString,startValue,destValue);
    pathString.pop_back();
    pathString+='R';
    TreeNode* r=lca(node->right,pathString,startValue,destValue);
    pathString.pop_back();
    if(l&&r || node->val==startValue||node->val==destValue) return node;
    return l==NULL?r:l;
 }

    //void dfs(TreeNode)
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathString="";
        TreeNode* lcaNode=lca(root,pathString,startValue,destValue);
        int cmn=0,i=0,j=0;
        while(i<startString.size()&&j<endString.size()){
            if(startString[i]==endString[j]){
                cmn++;
                i++; j++;
            }else break;
        }

        string ans="";
        for(int i=cmn;i<startString.size();i++) ans+='U';
        for(int i=cmn;i<endString.size();i++) ans+=endString[i];
        return ans;

    }
};