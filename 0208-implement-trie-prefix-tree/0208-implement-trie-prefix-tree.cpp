class TrieNode{
    public:
    bool isCompleted;
    TrieNode *children[26];
    TrieNode(){
        isCompleted=false;
        memset(children,0,sizeof(children));
    }
    
};

class Trie { 
    TrieNode* root;
    
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto ch:word){
            int idx=ch-97;
            if(node->children[idx]==NULL) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isCompleted=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(auto ch:word){
            int idx=ch-97;
            if(node->children[idx]==NULL) return false;
            node=node->children[idx];
        }
        return node->isCompleted;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(auto ch:prefix){
            int idx=ch-97;
            if(node->children[idx]==NULL) return false;
            node=node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */