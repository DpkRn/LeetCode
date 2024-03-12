class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &grid,int m,int n,int dx[],int dy[]){
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int newx=dx[i]+r;
            int newy=dy[i]+c;
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&grid[newx][newy]==1){
                dfs(newx,newy,grid,m,n,dx,dy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,m,n,dx,dy);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid,m,n,dx,dy);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,m,n,dx,dy);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid,m,n,dx,dy);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                   
                }
            }
        }
        return cnt;
    }
};