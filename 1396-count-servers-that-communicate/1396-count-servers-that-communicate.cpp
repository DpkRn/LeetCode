class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
            int n=grid[0].size();
            int m=grid.size();
            vector<int> row(m,0);
            vector<int> col(n,0);
            int cnt=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    row[i]+=(grid[i][j]==1);
                    col[j]+=(grid[i][j]==1);
                }
                cout<<row[i]<<endl;
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        if(col[j]>1||row[i]>1) cnt++;
                    }
                }
            }
            return cnt;
     
    }
};