class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int col=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<matrix[i][col]) col=j;  
            }
            int num=matrix[i][col];
            for(int k=0;k<m;k++){
               if(matrix[k][col]>num) num=matrix[k][col];
            }
            if(matrix[i][col]==num) 
            ans.push_back(num);
        }
        return ans;
    }
};

/*
//using unordered_map

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row[m],col[n];

        for(int i=0;i<m;i++){
            row[i]=1e9;
            for(int j=0;j<n;j++){
                row[i]=min(matrix[i][j],row[i]);  
            }
        }

        for(int i=0;i<n;i++){
            col[i]=-1e9;
            for(int j=0;j<m;j++){
                col[i]=max(matrix[j][i],col[i]);  
            }
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==col[j]) ans.push_back(row[i]);
            }
        }
        return ans;
    }
};

*/