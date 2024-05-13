class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rowCnt(m,0),colCnt(n,0);
        int s=0;
        
    
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++)
                grid[i][j]=!grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                colCnt[j]+=grid[i][j];
                
            }
        }
        
        for(int i=0;i<n;i++){
            if(m-colCnt[i]>colCnt[i]){
                for(int j=0;j<m;j++){
                    grid[j][i]=!grid[j][i];
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int temp=0;
           for(int j=n-1;j>=0;j--){
               if(grid[i][j]==1){
                   temp+=(1<<(n-1-j));
               }
           }
           // cout<<temp<<endl;
            ans+=temp;
        }
      //  for(auto it:colCnt) cout<<it<<" "; cout<<endl;
        // for(auto it:grid){
        //     for(auto el:it) cout<<el<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};