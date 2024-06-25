class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(flip%2==1&&nums[i]==1||flip%2==0&&nums[i]==0) flip++;
        }
        return flip;
    }
};