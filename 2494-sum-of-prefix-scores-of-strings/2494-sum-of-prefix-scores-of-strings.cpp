class Solution {
public:
    class TrieNode {
         public:
        TrieNode *children[26];
         int cnt;

   
        TrieNode() {
            memset(children, 0, sizeof(children));
            cnt = 0;
        }
    };


    class Trie{
         public:
        TrieNode* root;
       
        Trie(){
            root=new TrieNode();
        }
        void insert(string str){
            TrieNode* curr=root;
            for(auto ch:str){
                int idx=ch-'a';
                if(!curr->children[idx]) curr->children[idx]=new TrieNode();
                curr=curr->children[idx];
                curr->cnt+=1;
            }
        }
        int getSc(string str){
            TrieNode* curr=root;
            int sc=0;
            for(auto ch:str){
                int idx=ch-'a';
                if(!curr->children[idx]) break;
                curr=curr->children[idx];
                sc+=curr->cnt;
            }
            return sc;
        }
        
    };
    vector<int> sumPrefixScores(vector<string>& words) {
         vector<int> ans;
         Trie root;
         for(auto word:words){
            root.insert(word);
         }
         for(auto word:words){
            int sc=root.getSc(word);
            ans.push_back(sc);
         }
         return ans;
    }
};