class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;;
    bool isValid(int r,int c){
        int n=board.size();
         int x=r,y=c;
        for(int i=0;i<=r;i++){
                if(board[i][c]=='Q') return false;            
        }
       
        while(x>=0&&y>=0){
            if(board[x][y]=='Q') return false;
            x--;y--;
        }
         while(r>=0&&c>=0){
            if(board[r][c]=='Q') return false;
            r--;c++;
        }
        return true;
    }
    void solve(int i){
        if(i==board.size()){
           ans.push_back(board);
           return ;
        }
        for(int j=0;j<board.size();j++){
            if(isValid(i,j)==1){
                board[i][j]='Q';
                solve(i+1);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++) str.push_back('.');
        board=vector<string>(n,str);
        solve(0);
        return ans;
    }
};