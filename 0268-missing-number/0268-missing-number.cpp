class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(auto it:nums) st.insert(it);
        for(int i=0;i<=n;i++) if(!st.contains(i)) return i;
        return 0;
    }
};