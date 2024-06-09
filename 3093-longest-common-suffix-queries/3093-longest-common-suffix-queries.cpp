class TrieNode{
    public:
    int idx;
    TrieNode* children[26];
    TrieNode(){
        memset(children,0,sizeof(children));
    }
    TrieNode(int ind){
        idx=ind;
        memset(children,0,sizeof(children));
    }
};
class Solution {
public:
    void insert(TrieNode* root,string word,int ind,vector<string>& wordsContainer){
        TrieNode* node=root;
        reverse(word.begin(),word.end());
        for(auto ch:word){
            int idx=ch-97;
            if(node->children[idx]==NULL){
                node->children[idx]=new TrieNode();
                node=node->children[idx];
                node->idx=ind;
            }
            else{
                node=node->children[idx];
                if(wordsContainer[node->idx].size()>wordsContainer[ind].size())                                         node->idx=ind;
            }
           // node=node->children[idx];
        }
    }
//     void print(TrieNode* root){
//         if(root==NULL) return;
//         for(int i=0;i<26;i++){
//             if(root->children[i]!=NULL){
//                 char ch=i+97;
//                 cout<<ch<<"-"<<root->children[i]->idx<<"  ";
               
//                 print(root->children[i]);
//                  cout<<endl;
//             }
//         }
//     }
    
    int getInd(TrieNode* root,string str){
        TrieNode* node=root;
        reverse(str.begin(),str.end());
        for(auto ch:str){
            int idx=ch-97;
            if(node->children[idx]==NULL) return node->idx;
            node=node->children[idx];
        }
        return node->idx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        int minLenthInd=1e9;
        int minLength=1e9;
        for(auto i=0;i<wordsContainer.size();i++){
            if(wordsContainer[i].size()<minLength){
                minLength=wordsContainer[i].size();
                minLenthInd=i;
            }
        }
        TrieNode* root=new TrieNode(minLenthInd);
        for(auto i=0;i<wordsContainer.size();i++){
            insert(root,wordsContainer[i],i,wordsContainer);
        }
       //print(root);
        for(auto str:wordsQuery){   
            ans.push_back(getInd(root,str));
        }
        return ans;
    
    }
};