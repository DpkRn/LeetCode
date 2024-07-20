class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>>arr (m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=arr[i][j];
                colSum[j]-=arr[i][j];
            }
        }
        return arr;
    }
};