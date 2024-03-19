class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==-1) return -1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        // vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         vector[i][j]={i,j};
        //     }
        // }
        pq.push({1,0,0});
        while(!pq.empty()){
            int upto=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newx=r+i; int newy=c+j;
                    if(newx>=0&&newx<n&&newy>=0&&newy<n&&grid[newx][newy]==0){
                        if(upto+1<dist[newx][newy]){
                            dist[newx][newy]=upto+1;
                            pq.push({dist[newx][newy],newx,newy});
                        }
                    }
                }
            }
            
        }
        for(auto it:dist){
            for(auto itr:it) cout<<itr<<" "; cout<<endl;
        }
        
        return dist[n-1][n-1]==1e9?-1:dist[n-1][n-1];
    }
};