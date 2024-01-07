class Solution {
public:
    
    //checking is that valid index
    bool isValid(int r,int c,vector<vector<int>> &visited){
        if(r>=0&&r<visited.size()&&c>=0&&c<visited[0].size()&&visited[r][c]==0)
            return true;
        return false;
    }
    
    bool solve(int r,int c,string word,int ind,vector<vector<char>>& board, vector<vector<int>> &visited){
        if(ind>=word.size()){
            return true;
        }
        visited[r][c]=1;
        
        //check upSide
        if(isValid(r-1,c,visited)&&word[ind]==board[r-1][c]){  //if uppercell is valid and also equal to s[ind] check s[ind+1]index by all side
           if(solve(r-1,c,word,ind+1,board,visited))
               return true;
        }
        //right cell
        if(isValid(r,c+1,visited)&&word[ind]==board[r][c+1]){
           if(solve(r,c+1,word,ind+1,board,visited))
               return true;
        }
        //downWard
        if(isValid(r+1,c,visited)&&word[ind]==board[r+1][c]){
           if(solve(r+1,c,word,ind+1,board,visited))
               return true;
        }
        //leftWard
        if(isValid(r,c-1,visited)&&word[ind]==board[r][c-1]){
           if(solve(r,c-1,word,ind+1,board,visited))
               return true;
        }
        visited[r][c]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(board[i][j]==word[0])
                   if(solve(i,j,word,1,board,visited))
                       return true;
           }
       }
        return false;
    }
};