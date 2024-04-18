class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
       // vector<vector<int>>vis(m,vector<int> (n,0));
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int x=0;x<4;x++){
                        int newx=i+dx[x];
                        int newy=j+dy[x];
                        if(!(newx>=0&&newx<m&&newy>=0&&newy<n&&grid[newx][newy]==1)){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};