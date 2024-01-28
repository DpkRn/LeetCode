class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
        stack<int> st;
        int dp[n];
        for(int i=n-1;i>=0;i--){
        while(!st.empty()&&nums2[st.top()]<=nums2[i]) st.pop();
            if(st.empty()) dp[i]=-1;
            else dp[i]=nums2[st.top()];
            st.push(i);
        }
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
           mp[nums2[i]]=dp[i]; 
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }
};