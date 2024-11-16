class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,-1);
        for(int i=0;i<n-k+1;i++){
            int j=i;
            while(j<i+k-1&&nums[j]==nums[j+1]-1) j++;
            if(j==i+k-1) ans[i]=nums[i+k-1];
        }
        return ans;
    }
};