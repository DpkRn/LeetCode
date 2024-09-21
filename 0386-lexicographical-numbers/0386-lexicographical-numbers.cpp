class Solution {
    bool dfs(int curr, int n, auto& res){
        if(curr>n) return false;
        res.push_back(curr);
        for(int i=0;i<=9;i++){
            if(!dfs(curr*10+i,n,res)) break;
        }
        return true;
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++){
            if(!dfs(i,n,res)) break;
        }
        return res;
    }
};