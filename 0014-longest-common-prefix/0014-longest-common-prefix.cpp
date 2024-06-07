//using Trie Concept its long but if want to show short method look below using greedy
class TrieNode{
    public:
    bool isCompleted;
    TrieNode* children[26];
    TrieNode(){
        memset(children,0,sizeof(children));
        isCompleted=false;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root=new TrieNode();
        
        for(auto str:strs){
            if(str=="") return "";
            TrieNode* node=root;
            for(auto ch:str){
                int idx=ch-97;
                if(node->children[idx]==NULL) node->children[idx]=new TrieNode();
                node=node->children[idx];
            }
            
            node->isCompleted=true;
        }
        
        
       TrieNode* node=root;
        string ans="";
        while(true){
            int cnt=0,idx=0;
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                   cnt++;
                   idx=i;
                }
            }
            if(cnt!=1) return ans;
            char ch=97+idx;
            ans.push_back(ch);       
            node=node->children[idx];
            if(node->isCompleted==true) return ans;
            
        }
        return ans;
    }
};

//using greedy
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
*/