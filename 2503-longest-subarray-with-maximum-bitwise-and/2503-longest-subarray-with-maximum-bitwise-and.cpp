class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        int cnt=0,maxi=1;
        for(int i=0;i<n;i++){
            cnt=nums[i]==m?cnt+1:0;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};