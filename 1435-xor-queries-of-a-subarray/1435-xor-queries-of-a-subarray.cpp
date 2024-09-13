class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> preSum(n,0);
        preSum[0]=arr[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto it:queries){
           int zorr=preSum[it[1]]^preSum[it[0]]^arr[it[0]];
           ans.push_back(zorr);
        }
        return ans;
    }
};