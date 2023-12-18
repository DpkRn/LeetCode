class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
          vector<int> ans;
        int top=0,left=0,right=n;
        int bottom=m;


    while(left<=right&&top<=bottom){
        //visit right
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        //visit bottom
        
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
       if(top<=bottom)
        for(int i=right;i>=left;i--){
           ans.push_back(matrix[bottom][i]);
        }
        bottom--;
         if(left<=right)
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
    }

   return ans;
    }
};