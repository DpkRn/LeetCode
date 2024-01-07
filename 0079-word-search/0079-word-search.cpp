class Solution {
public:
    bool isValid(int r,int c,vector<vector<int>> &visited){
        if(r>=0&&r<visited.size()&&c>=0&&c<visited[0].size()&&visited[r][c]==0)
            return true;
        return false;
    }
    bool solve(int r,int c,string word,int ind,vector<vector<char>>& board, vector<vector<int>> &visited){
        if(ind>=word.size()){
            return true;
        }
        //check upSide
        if(isValid(r-1,c,visited)&&word[ind]==board[r-1][c]){
            visited[r-1][c]=1;
           if(solve(r-1,c,word,ind+1,board,visited))
               return true;
            visited[r-1][c]=0;
        }
        //right cell
        if(isValid(r,c+1,visited)&&word[ind]==board[r][c+1]){
            visited[r][c+1]=1;
           if(solve(r,c+1,word,ind+1,board,visited))
               return true;
            visited[r][c+1]=0;
        }
        //downWard
        if(isValid(r+1,c,visited)&&word[ind]==board[r+1][c]){
            visited[r+1][c]=1;
           if(solve(r+1,c,word,ind+1,board,visited))
               return true;
            visited[r+1][c]=0;
        }
        //leftWard
        if(isValid(r,c-1,visited)&&word[ind]==board[r][c-1]){
            visited[r][c-1]=1;
           if(solve(r,c-1,word,ind+1,board,visited))
               return true;
            visited[r][c-1]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m*n;i++){
            if(board[i/n][i%n]==word[0]){
                visited[i/n][i%n]=1;
                if(solve(i/n,i%n,word,1,board,visited))
                    return true;
                visited[i/n][i%n]=0;
            }
        }
        return false;
    }
};