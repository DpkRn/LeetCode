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
             if(dfs(newx,newy,ind+1,board,word,m,n))
                return true;
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
};