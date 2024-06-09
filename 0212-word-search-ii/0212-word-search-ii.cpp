//using try (m*n*words.lenth*10)
class TrieNode{
    public:
    string word;
    bool isCompleted;
    TrieNode* children[26];
    TrieNode(){
        word="";
        isCompleted=false;
        memset(children,0,sizeof(children));
    }    
};

class Solution {
    vector<string> ans;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
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
    
    void dfs(int r,int c,TrieNode* node,vector<vector<char>>& board,int m,int n){
        if(node->isCompleted==true) {
            ans.push_back(node->word);
            node->isCompleted=false;
        }
        char org=board[r][c];
            board[r][c]='#';
         for(int i=0;i<4;i++){
             int newx=r+dx[i],newy=dy[i]+c;
             if(newx>=0&&newy>=0&&newx<m&&newy<n&&board[newx][newy]!='#'&&node->children[board[newx][newy]-97]!=NULL){
                dfs(newx,newy,node->children[board[newx][newy]-97],board,m,n);
             }
          }
        board[r][c]=org;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       
       TrieNode* root=new TrieNode();
        for(auto str:words){
            insert(root,str);
        }
        
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->children[board[i][j]-97]!=NULL){
                    dfs(i,j,root->children[board[i][j]-97],board,m,n);
                }
            }
        } 
        return ans;
    }
};

//Brute force 
/*
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    bool dfs(int r,int c,int ind,vector<vector<char>>& board, string word,int m,int n){
        if(ind>=word.size()) return true;
        char org=board[r][c];
            board[r][c]='#';
         for(int i=0;i<4;i++){
             int newx=r+dx[i],newy=dy[i]+c;
             if(newx>=0&&newy>=0&&newx<m&&newy<n&&board[newx][newy]!='#'&&board[newx][newy]==word[ind]){
                 if(dfs(newx,newy,ind+1,board,word,m,n)){
                    board[r][c]=org;
                    return true;
                 }
             }
          }
        board[r][c]=org;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,1,board,word,m,n)) return true;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        for(auto word:words){
            if(exist(board,word)) ans.push_back(word);
        }
        return ans;
    }
};
*/