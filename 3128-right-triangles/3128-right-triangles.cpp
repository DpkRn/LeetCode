class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    ans += 1LL * (row[i] - 1) * (col[j] - 1);
                }
            }
        }
        return ans;
    }
};