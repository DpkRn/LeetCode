class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            int maxi=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            if(r==m-1&&c==n-1) return maxi;
            pq.pop();
            for(int i=0;i<4;i++){
                int newx=dx[i]+r; int newy=dy[i]+c;
                if(newx>=0&&newx<m&&newy>=0&&newy<n){
                   int neweffort=max(abs(heights[r][c]-heights[newx][newy]),maxi);
                    if(neweffort<dist[newx][newy]){
                        dist[newx][newy]=neweffort;
                        pq.push({neweffort,newx,newy});
                    }        
                }
                
            }
        }
       
        return 0;
    }
};