class Solution {
public:
    bool search(int r,int c,string word,int ind,vector<vector<char>>&board){
        if(ind==word.size()) return true;
        if(r<0||c<0||r==board.size()||c==board[0].size()||board[r][c]!=word[ind]) return false;
        board[r][c]='#';
        bool up=search(r-1,c,word,ind+1,board);
        bool right=search(r,c+1,word,ind+1,board);
        bool down=search(r+1,c,word,ind+1,board);
        bool left=search(r,c-1,word,ind+1,board);
        board[r][c]=word[ind];
        return up||right||down||left;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,word,0,board))
                        return true;
                }
                
            }
        }
        return false;
    }
};