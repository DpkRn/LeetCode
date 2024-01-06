class Solution {
public:
    void solve(int ind,int k,int n,vector<int>&temp,vector<vector<int>> &ans){
        
        if(k==temp.size()){
            if(n==0){
                ans.push_back(temp);
            }
            return ;
        }
        if(ind>9)
            return;
        
        if(n>=ind){
        temp.push_back(ind);
        solve(ind+1,k,n-ind,temp,ans);
        temp.pop_back();
       }
        solve(ind+1,k,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,k,n,temp,ans);
        return ans;
    }
};