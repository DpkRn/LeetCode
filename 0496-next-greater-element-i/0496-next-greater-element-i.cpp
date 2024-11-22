class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        int n=nums2.size();
        vector<int> vec(nums1.size(),-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&(st.top()<=nums2[i])){
                st.pop();
            }
            if(mp.find(nums2[i])!=mp.end())
            vec[mp[nums2[i]]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }

        return vec;
    }
};