class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
         vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][n-1]=='O')
            {   q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[m-1][i]=='O'){
                 q.push({m-1,i});
                vis[m-1][i]=1;
            }
               
            
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=dx[i]+x; int newy=dy[i]+y;
                if(newx>=0&&newx<m&&newy>=0&&newy<n&&board[newx][newy]!='X'&&!vis[newx][newy]){
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
       
        
    }
};