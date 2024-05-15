class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    vector<vector<int>> safeDistanceDp;
    int preComputeSafeDist(auto &grid){
        int n=grid.size();
        safeDistanceDp=vector<vector<int>>(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        int len=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first, c=q.front().second;
                q.pop();
                safeDistanceDp[r][c]=len;
                for(int i=0;i<4;i++){
                    int newx=r+dx[i], newy=c+dy[i];
                    if(newx>=0&&newx<n&&newy>=0&&newy<n&&!vis[newx][newy]){
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }
            len++;
        }
        return len;
    }
    bool isSafe(int ftr,auto &grid){
        if(ftr>safeDistanceDp[0][0]) return false;
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            if(r==n-1&&c==n-1) return true;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=r+dx[i],newy=c+dy[i];
                if(newx>=0&&newx<n&&newy>=0&&newy<n&&!vis[newx][newy]&&ftr<=safeDistanceDp[newx][newy]){
                    q.push({newx,newy});
                    vis[newx][newy]=true;
                }
            }
            
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int l=0;
        int r=preComputeSafeDist(grid);
        while(l<=r){
            int m=l+(r-l)/2;
            if(isSafe(m,grid))
                l=m+1;
            else r=m-1;
        }
         return r;
        
    }
};