class Solution {
public:
    bool isValid(char n,int i,int j,auto &board){
        for(int k=0;k<9;k++){
            if(k!=j&&board[i][k]==n) return false;
            if(k!=i&&board[k][j]==n) return false;
            int r=(i/3)*3+k/3;
            int c=(j/3)*3+k%3;
            if(r!=i&&c!=j&&board[r][c]==n) return false;
        }
        return true;
       
    }
   
    bool isValidSudoku(vector<vector<char>>& board) {
      for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              if(board[i][j]!='.'){
                  if(!isValid(board[i][j],i,j,board))
                     return false;
              }
          }
      }
       return true;      
    }
};