class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void checkIs(int r,int c,vector<vector<char>> &grid,int m,int n){
        if(r<m&&r>=0&&c<n&&c>=0&&grid[r][c]=='1'){
            grid[r][c]=0;
            for(int i=0;i<4;i++){
                checkIs(r+dx[i],c+dy[i],grid,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    checkIs(i,j,grid,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};