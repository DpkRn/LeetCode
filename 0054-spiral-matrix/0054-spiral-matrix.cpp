class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int down=matrix.size()-1;
        int left=0; int right=matrix[0].size()-1;
        vector<int> ans;
        while(top<=down&&left<=right){
            //upper row
            for(int i=left;i<=right&&top<=down;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //right column
            for(int i=top;i<=down&&left<=right;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //bottom row
            for(int i=right;i>=left&&top<=down;i--){
                ans.push_back(matrix[down][i]);
            }
            down--;

            //left column
            for(int i=down;i>=top&&left<=right;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;

        }
        return ans;
    }
};