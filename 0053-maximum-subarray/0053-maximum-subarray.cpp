class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;int maxSum=-1e9;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            sum=sum<0?0:sum;
        }
        return maxSum;
    }
};