class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(auto i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        stack<int> st;
        vector<int> dp(2*n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i]) st.pop();
            if(!st.empty()) dp[i]=st.top();
            else dp[i]=-1;
            st.push(nums[i]);
        }
         dp.resize(n);
        return dp;
    }
};