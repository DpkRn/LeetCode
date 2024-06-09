class TrieNode{
    public:
    bool isCompleted;
    string word;
    TrieNode* children[26];
    TrieNode(){
        word="";
        memset(children,0,sizeof(children));
        isCompleted=false;
    }
};
class Solution {
    
public:
    void insert(TrieNode* root,string word){
        TrieNode* node=root;
        for(auto ch:word){
            int idx=ch-97;
            if(node->children[idx]==NULL) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->word=word;
        node->isCompleted=true;
    }
    string search(TrieNode* root,string word){
        TrieNode* node=root;
        for(auto ch:word){
            int idx=ch-97;
            if(node->children[idx]==NULL) return "";
            node=node->children[idx];
            if(node->isCompleted) return node->word;
        }
        return node->word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root=new TrieNode();
        for(auto word:dictionary){
            insert(root,word);
        }
        stringstream ss(sentence);
        vector<string> st;
        string temp;
        while(ss>>temp){
            st.push_back(temp);
        }
        string ans="";
        for(auto str:st){
            string der=search(root,str);
            if(der=="") ans+=str;
            else ans+=der;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
    }
};
/*
//using hash brute force 

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,string> mp;
        int n=dictionary.size();
        stringstream ss(sentence);
        vector<string> st;
        string temp;
        while(ss>>temp){
            st.push_back(temp);
        }
        
        for(int i=0;i<n;i++){
            int sz=dictionary[i].size();
            for(auto str:st){
                if(str.size()<sz) continue;
                string word(str.begin(),str.begin()+sz);
                if(word==dictionary[i]){
                    if(mp.find(str)==mp.end()||mp[str].size()>dictionary[i].size()){
                        mp[str]=dictionary[i];
                    } 
                }
            }
        }
        
        string ans="";
        for(auto str:st){
            if(mp.find(str)!=mp.end()){
                ans+=mp[str];
                
            }else ans+=str;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};
*/