class Solution {
public:
    void f(int i,int k,auto &path,auto &ans,int n){
        if(k==0){
            ans.push_back(path);
            return ;
        }
        if(i>n) {
            
        return ;
    }
    f(i+1,k,path,ans,n);
    path.push_back(i);
    f(i+1,k-1,path,ans,n);
    path.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        f(1,k,path,ans,n);
        return ans;
    }
};