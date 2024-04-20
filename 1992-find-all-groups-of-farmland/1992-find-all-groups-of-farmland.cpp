class Solution {
public:
    void solve(vector<vector<int>> &land,int r,int c,int m,int n,vector<vector<int>>&vis,vector<vector<int>> &ans){
        queue<pair<int,int>> q;
         vector<int> temp(4);
        q.push({r,c});
         
        vis[r][c]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};  
        temp[0]=r;temp[1]=c;
      
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(q.empty()){
               
            }
            for(int i=0;i<4;i++){
                int newx=dx[i]+x;
                int newy=dy[i]+y;
                if(newx>=0&&newy>=0&&newx<m&&newy<n&&vis[newx][newy]!=1&&land[newx][newy]==1){
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
            if(q.empty()){
                temp[2]=x; temp[3]=y;
                ans.push_back(temp);
            }
        }                
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
         vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1&&vis[i][j]!=1){
                    solve(land,i,j,m,n,vis,ans);
                }
            }
        }
        return ans;
    }
};