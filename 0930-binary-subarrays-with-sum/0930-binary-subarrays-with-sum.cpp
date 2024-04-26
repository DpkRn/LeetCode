class Solution {
public:
    //we cant find directely the exact subarray count with sum given goal so that we will find first 
    //subarray sum <=goal and substract the sum<=goal-1 
    //so we need to write a function to find the sum<=goal
    int getSmallerEqualSumCount(vector<int> &nums,int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int sum=0,cnt=0,l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal) cnt+=(r-l+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return getSmallerEqualSumCount(nums,goal)- getSmallerEqualSumCount(nums,goal-1);
    }
};