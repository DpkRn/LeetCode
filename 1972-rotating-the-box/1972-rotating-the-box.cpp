class Solution {
public:
    void shift(vector<char> &row,int r){
        int i=row[r]=='*'?r-1:r;
        for(;i>=0&&row[i]!='*';i--){
            while(r>i&&row[r]!='.') r--;
           if(row[i]=='#'){
            swap(row[i],row[r]);
           }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(box[i][j]=='*'||j==n-1){
                    shift(box[i],j);
                }
            }
        }
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               ans[j][i]=box[i][j];
            }
        }
        for(auto &row:ans){
            reverse(row.begin(),row.end());
        }

        
        return ans;
    }
};