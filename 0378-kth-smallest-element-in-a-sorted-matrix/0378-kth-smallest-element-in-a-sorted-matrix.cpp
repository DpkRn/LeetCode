class Solution {
public:
    //O(mnlog mn) O(mn)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for(auto it:matrix){
           ans.insert(ans.end(),it.begin(),it.end());
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};