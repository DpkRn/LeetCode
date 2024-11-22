class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(auto &row:matrix){
            vector<int> flip(n,0);
            for(int i=0;i<n;i++){
                flip[i]=1-row[i];
            }
            int cnt=0;
            for(auto &currRow:matrix){
                if(flip==currRow|| row==currRow) cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};