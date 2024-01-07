class Solution {
    pair<int,int> findNext(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    return make_pair(i,j);
            }
        }
        return {9,9};
    }
    bool isValid(char num,int r,int c,vector<vector<char>> &board){
        int cellR=(r/3)*3;
        int cellC=(c/3)*3;
        for(int i=0;i<9;i++){
            if(board[r][i]==num||board[i][c]==num)
                return false;
        }
        for(int i=cellR;i<cellR+3;i++){
            for(int j=cellC;j<cellC+3;j++){
                if(board[i][j]==num)
                    return false;
            }
        }
        return true;
        
        
    }
    bool solve(int r,int c,vector<vector<char>>&board){
        if(r>=9||c>=9)
            return true; 
        
        for(char num='1';num<='9';num++){
            if(isValid(num,r,c,board)){
                board[r][c]=num;
                pair<int,int> cell=findNext(board);
                if(solve(cell.first,cell.second,board)) return true;
                board[r][c]='.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        pair<int,int> cell=findNext(board);
        int r=cell.first; int c=cell.second;
        solve(r,c,board);
    }
};