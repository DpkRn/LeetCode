class Solution {
public:
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                q.push({i,j,0});
                vis[i][j]=1;
                }
            }
        }
        
         while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int dist=q.front()[2];
            cout<<x<<" "<<y<<" "<<dist<<endl;
            q.pop();
            ans[x][y]=dist;
            for(int i=0;i<4;i++){
                int newx=dx[i]+x,newy=dy[i]+y;
                if(newx>=0&&newx<m&&newy>=0&&newy<n&&vis[newx][newy]==0){
                    vis[newx][newy]=1;
                    q.push({newx,newy,dist+1});
                }
            }        
        }
        
        return ans;           
        
    }
};