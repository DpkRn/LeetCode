class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,0); 
        vector<int> ans;
        for (int i = 1; i<n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                dp[i] = dp[i-1] + 1;
            }
        }

        for (int i = 0; i<=n-k; i++) {
            if (dp[i+k-1] == dp[i] + k-1) {
                ans.push_back(nums[i+k-1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};