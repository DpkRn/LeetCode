class TrieNode{
    public:
    TrieNode* children[2];
    TrieNode(){
        memset(children,0,sizeof(children));
    }
};
class Solution {
        
public:
    void insert(TrieNode* root,int num){
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int ithBit=(num>>i)&1;
            if(node->children[ithBit]==NULL) node->children[ithBit]=new TrieNode();
            node=node->children[ithBit];
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        for(auto num:nums) insert(root,num);
        int maxi=0;
        for(auto num:nums){
            TrieNode *node=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int ithBit=(num>>i)&1;
                if(node->children[!ithBit]!=NULL){
                    ans+=(1<<i);
                    node=node->children[!ithBit];
                }else{
                    node=node->children[ithBit];
                }
            }
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};