class Solution {
public:
    void solve(vector<int> &candidates,int ind,int target,vector<int>&temp,vector<vector<int>> &ans){
       if(target==0){
           ans.push_back(temp);
           return;
       }
        for(int i=ind;i<candidates.size();i++){
            if(ind!=i&&candidates[i-1]==candidates[i]) 
                continue;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                solve(candidates,i+1,target-candidates[i],temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>> ans;
        solve(candidates,0,target,temp,ans);
        return ans;
    }
};