class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> mp(2,0);
        int n=nums.size();
        int l=0,maxi=0; 
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[0]>k){
                mp[nums[l]]--;
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};