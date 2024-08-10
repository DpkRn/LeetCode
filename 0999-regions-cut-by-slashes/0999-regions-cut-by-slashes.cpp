class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void dfs(int r,int c,vector<vector<int>> &mat){
        mat[r][c]=1;
        for(int i=0;i<4;i++){
            int x=dx[i]+r; int y=dy[i]+c;
            if(x>=0&&x<mat.size()&&y>=0&&y<mat[0].size()&&mat[x][y]==0){
                dfs(x,y,mat);
            }
        }

    }
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> mat(m*3,vector<int>(n*3,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1; mat[i*3+1][j*3+1]=1; mat[i*3+2][j*3+2]=1;
                }else if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1; mat[i*3+1][j*3+1]=1; mat[i*3+2][j*3]=1;
                }
            }
        }

        for(int i=0;i<m*3;i++){
            for(int j=0;j<n*3;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        int cnt=0;
        for(int i=0;i<m*3;i++){
            for(int j=0;j<n*3;j++){
                if(mat[i][j]==0){
                    dfs(i,j,mat);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};