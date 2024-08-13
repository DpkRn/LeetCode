class Solution {
public:
    void dfs(int i,auto &candidates,int target,vector<int> &path, vector<vector<int>> &ans,int n){    
        if(target==0){
            ans.push_back(path);
            return;
        }
        for(int j=i;j<n;j++){
            if(i!=j&&candidates[j]==candidates[j-1]) continue;
             if(target-candidates[i]>=0) {
                path.push_back(candidates[j]);
                dfs(j+1,candidates,target-candidates[j],path,ans,n);
                path.pop_back();
             }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target,path,ans,n);
        return ans;
    }
};