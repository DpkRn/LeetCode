class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=n;
        int l=0;int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>=target){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};