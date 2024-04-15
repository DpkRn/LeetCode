class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        stack<int> st;
        vector<int> next(n2);
        for(int i=n2-1;i>=0;i--){
            
            while(!st.empty()&&st.top()<=nums2[i]) st.pop();
            if(!st.empty())
                next[i]=st.top();
            else 
                next[i]=-1;
            st.push(nums2[i]);
        }
        int n1=nums1.size();
        vector<int> ans(n1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=next[j];
                    break;
                }
            }
        }
        return ans;
    }
};