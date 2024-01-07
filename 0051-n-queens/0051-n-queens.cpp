class Solution {
    bool isValidMove(int c,int r,vector<string> &chess,int n){
        int x=c; int y=r;
        //checking upper  diagonal
        while(x>=0&&y>=0){
            if(chess[y][x]=='Q')
                return false;
            x--;y--;
        }
        
        x=c;y=r;
         //checking left  
        while(x>=0){
            if(chess[y][x]=='Q')
                return false;
            x--;
        }
          //checking down  diagonal
        x=c;y=r;
        while(x>=0&&y<n){
            if(chess[y][x]=='Q')
                return false;
            x--;y++;
        }
        return true;
        
        
    }
    void solve(int c,vector<string> &chess,vector<vector<string>> &ans,int n){
        if(c>=n){
            ans.push_back(chess);
            return;
        }
        for(int r=0;r<n;r++){
            if(isValidMove(c,r,chess,n)){
                chess[r][c]='Q';
                solve(c+1,chess,ans,n);
                chess[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>chess;
        string str(n,'.');
        for(int i=0;i<n;i++){
            chess.push_back(str);
        }
        solve(0,chess,ans,n);
        return ans;
        
    }
};