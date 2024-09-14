class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int sub=1,curr=nums[0];
        int i=0,j=1;
        while(j<n){
            if(nums[j]<curr){
                sub=max(sub,j-i);
                i=j+1;
            }
            else if(nums[j]>curr){
                curr=nums[j];
                sub=1;
                i=j;
            }
            j++;
        }
        return max(sub,j-i);
    }
};