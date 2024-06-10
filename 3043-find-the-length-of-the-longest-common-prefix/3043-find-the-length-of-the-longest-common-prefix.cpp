class TrieNode{
    public:
    bool isCompleted;
    int len;
    TrieNode* children[10];
    TrieNode(){
        len=0;
        isCompleted=false;
        memset(children,0,sizeof(children));
    }
   
};
class Solution {
public:
    void insert( TrieNode* root,int num){
        TrieNode* node=root;
        vector<int> rev_arr;
        while(num>0){
            rev_arr.push_back(num%10);
            num/=10;
        }
        reverse(rev_arr.begin(),rev_arr.end());
        int len=1;
        for(auto ch:rev_arr){
            int idx=ch;
            if(node->children[idx]==NULL){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
            node->len=len++;
        }
        node->isCompleted=true;
    }
    int search(TrieNode* root,int num){
        TrieNode* node=root;
        vector<int> rev_arr;
        while(num>0){
            rev_arr.push_back(num%10);
            num/=10;
        }
        reverse(rev_arr.begin(),rev_arr.end());
        int len=1;
        for(auto ch:rev_arr){
            int idx=ch;
            if(node->children[idx]==NULL){
                return node->len;
            }
            node=node->children[idx];
            node->len=len++;
        }
        return node->len;
        
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root=new TrieNode();
        for(auto num:arr2){
            insert(root,num);
        }
        int maxi=-1e9;
        for(auto num:arr1){
            maxi=max(maxi,search(root,num));
        }
        return maxi;
    }
};