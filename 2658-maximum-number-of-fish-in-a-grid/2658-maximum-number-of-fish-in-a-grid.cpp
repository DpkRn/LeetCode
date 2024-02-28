class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    int getFish(int r,int c,vector<vector<int>>&grid,int m,int n){
        if(r<m&&r>=0&&c<n&&c>=0&&grid[r][c]>0){
            int cell=grid[r][c];
            grid[r][c]=0;
            for(int i=0;i<4;i++){
                cell+=getFish(r+dx[i],c+dy[i],grid,m,n);
            }
             return cell;
        }
       return 0;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxi=max(maxi,getFish(i,j,grid,m,n));
                }
            
            }
        }
        return maxi;
        
    }
};