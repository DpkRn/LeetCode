class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flip=0;
        int k=3;
        for(int i=0;i<n-2;i++){
            if(nums[i]) continue;
            for(int j=0;j<k;j++){
                nums[i+j]=nums[i+j]^1;
            }
            flip++;
        }
        if(nums[n-1]==0||nums[n-2]==0) return -1;
        return flip;
    }
};