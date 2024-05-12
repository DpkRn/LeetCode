class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int maxi=-1e9;
                for(int i1=0;i1<3;i1++){
                    for(int j1=0;j1<3;j1++){
                        maxi=max(maxi,grid[i+i1][j+j1]);
                    }
                }
                ans[i][j]=maxi;
            }
           
        }
        return ans;
    }
};