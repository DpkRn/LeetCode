class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          int m=matrix.size();
        int n=matrix[0].size();
        vector<int> col(n,1);
        for(int i=0;i<m;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                  flag=1;
                  col[j]=0;
                }
            }
            if(flag==1){
                for(int k=0;k<n;k++) matrix[i][k]=0;
            }

        }
       for(int i=0;i<n;i++){
         if(col[i]==0){
           for(int j=0;j<m;j++)
           matrix[j][i]=0;
          }
       }
    }
};