class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=INT_MIN;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) cnt++;
            else{
                maxi=max(maxi,cnt);
                cnt=0;
            }

        }
        return max(cnt,maxi);
    }
};