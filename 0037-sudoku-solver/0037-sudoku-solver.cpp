class Solution {
    bool isValid(char ch,int r,int c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[r][i]==ch) return false;
            if(board[i][c]==ch) return false;
            if(board[(r/3)*3+i/3][(c/3)*3+i%3]==ch) return false;
        }
        return true;
    }
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            else 
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};