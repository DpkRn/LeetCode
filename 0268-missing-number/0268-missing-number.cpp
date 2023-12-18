class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int zor=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            zor=zor^nums[i];
            zor=zor^i;
        }
        return zor^(n);
    }
};