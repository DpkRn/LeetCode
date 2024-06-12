class TrieNode{
    public:
    bool isCompleted;
    TrieNode* children[26];
    TrieNode(){
        isCompleted=false;
        memset(children,0,sizeof(children));
    }
    
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();  
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(auto ch:word){
            int idx=ch-97;
            
            if(node->children[idx]==NULL) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isCompleted=true;
    }
    bool dfs(string word,TrieNode* node){
       
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(auto c:node->children){
                    if(c&&dfs(word.substr(i+1),c))  return true;
                }
                return false;
            }
            int idx=word[i]-97;
            if(node->children[idx]==NULL) return false;
            node=node->children[idx];
        }
            return node->isCompleted;
    }
    bool search(string word) {
      return dfs(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */