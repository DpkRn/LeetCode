class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int ans=0;
        for(auto &row:matrix){
            string str="";
            int x=row[0];
            for(auto &it:row){
                str+=it==row[0]?'t':'f';
            }
            mp[str]++;
            ans=max(ans,mp[str]);

        }
        return ans;
    }
};