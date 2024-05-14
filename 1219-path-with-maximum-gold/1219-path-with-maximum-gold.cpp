class Solution {
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
public:
    void dfs(int r,int c,int &maxi,int s,auto &grid){
         int m=grid.size();
        int n=grid[0].size();
        s+=grid[r][c];
        maxi=max(maxi,s);
        int original=grid[r][c];
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int newx=r+dx[i]; int newy=c+dy[i];
            if(newx<m&&newx>=0&&newy<n&&newy>=0&&grid[newx][newy]!=0)
                dfs(newx,newy,maxi,s,grid);
        }        
        grid[r][c]=original;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int maxi=0;
                    dfs(i,j,maxi,0,grid);
                    ans=max(ans,maxi);
                }
            }
        }
        return ans;
    }
};