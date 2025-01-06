class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> dp;
        int n=boxes.size();
        for(int i=0;i<n;i++) if(boxes[i]=='1') dp.push_back(i);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<dp.size();j++){
                ans[i]+=(abs(i-dp[j]));
            }
        }
        return ans;
        
    }
};