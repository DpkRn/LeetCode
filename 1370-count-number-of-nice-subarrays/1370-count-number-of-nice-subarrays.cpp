class Solution {
public:
    int getCnt(vector<int>&nums,int k){
        int oddCnt=0,l=0,cnt=0, n=nums.size();
        for(int i=0;i<n;i++){
            oddCnt+=nums[i]%2==1;
            while(oddCnt>k){
                oddCnt-=nums[l++]%2==1;
            }
            cnt+=(i-l+1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return getCnt(nums,k)-getCnt(nums,k-1);
    }
};