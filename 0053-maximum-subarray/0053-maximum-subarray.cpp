class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best=-1e9,sum=0;
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],nums[i]+sum);
            best=max(sum,best);
        }
        return best;
    }
};
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum<0) sum=0;
            sum=sum+nums[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
*/