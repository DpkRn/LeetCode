class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        long long sum=0;
        int mini=1e9;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mini=min(abs(matrix[i][j]),mini);
                cnt+=(matrix[i][j]<0);
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt&1){
            sum-=(2*mini);
        }
        return sum;
    }
};