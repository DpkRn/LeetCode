class Solution {
public:
    void dfs(int r,int c,int src,int color,vector<vector<int>> &image,vector<vector<int>> &vis,int m,int n){
        image[r][c]=color;
        vis[r][c]=1;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int newx=r+dx[i]; int newy=c+dy[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&image[newx][newy]==src&&!vis[newx][newy]){
                dfs(newx,newy,src,color,image,vis,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int src=image[sr][sc];
        vector<vector<int>> vis(m,vector<int>(n,0));
        dfs(sr,sc,src,color,image,vis,m,n);
        return image;
    }
};