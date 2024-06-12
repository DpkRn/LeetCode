class TrieNode{
    public:
    int cnt;
    unordered_map<string,TrieNode*> mp;
    TrieNode(){
        cnt=0;
    }
   
};
class Solution {
public:
    int insert( TrieNode* root,string word){
        TrieNode* node=root;
        int ans=0;
        int n=word.size();
        int i=0,j=n-1;
        while(i<n){
            string sp=to_string(word[i])+to_string(word[j]);
            if(node->mp.find(sp)==node->mp.end()) node->mp[sp]=new TrieNode();
            node=node->mp[sp];
            ans+=node->cnt;
            i++;j--;
        }
        node->cnt+=1;
        return ans;
    }
  
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        long long ans=0;
        TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++){
            ans+=insert(root,words[i]); 
        }

        return ans;
    }
};