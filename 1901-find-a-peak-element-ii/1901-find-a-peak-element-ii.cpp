#include<bits/stdc++.h>
class Solution {
    int getMaxValRow(vector<vector<int>>& matrix,int col){
        int ind=-1;
        int maxi=INT_MIN;
        int m=matrix.size();
        for(int i=0;i<m;i++){
            if(matrix[i][col]>=maxi){
                maxi=matrix[i][col];
                ind=i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;int high=n-1;
        while(low<=high){
            int col=(low+high)>>1;
            int row=getMaxValRow(mat,col);
            cout<<mat[row][col]<<" ";
            int left=col-1>=0?mat[row][col-1]:-1;
            int right=col+1<n?mat[row][col+1]:-1;
            int mid=mat[row][col];
            if(left<mid&&mid>right) return {row,col};
            else if(left>mid) high=col-1;
            else low=col+1;
        }
        return {0,-1};
    }
};