class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        vector<int> dp(n,-1);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]) st.pop();
            if(!st.empty()) dp[i]=st.top();
            st.push(nums2[i]);
        }

    vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(dp[mp[nums1[i]]]);
        }
    return ans;
    }
};