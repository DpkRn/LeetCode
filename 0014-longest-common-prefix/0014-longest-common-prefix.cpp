class TrieNode{
    public:
    TrieNode *children[26];
    bool isCom;
    TrieNode(){
        memset(children,NULL,sizeof(children));
        isCom=false;
    }
};

class Solution {
public:
  
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root=new TrieNode();
        string ans="";
        for(auto str:strs){
             TrieNode* node=root;
             for(char ch:str){

                int idx=ch-'a';
                if(node->children[idx]==NULL) node->children[idx]=new TrieNode();
                node=node->children[idx];  
             }
             node->isCom=true;
             
        }
        string temp=strs[0];
        TrieNode* node=root;
        for(auto ch:temp){
            int cnt=0;
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    cnt++;
                }
            }
             if(cnt!=1 or node->isCom==true) return ans;
                ans+=ch;
            node=node->children[ch-'a'];
        }
       
     return ans;

    }
};