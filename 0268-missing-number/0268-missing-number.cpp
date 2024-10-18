class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); int zor=0;
        for(int i=1;i<=n;i++){
            zor^=nums[i-1];
            zor^=i;
        }
        return zor;
       
    }
};