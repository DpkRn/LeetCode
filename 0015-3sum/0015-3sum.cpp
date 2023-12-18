class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans; 
        for(int i=0;i<n;i++){
            if(i>0&&nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                   j++;
                    while(j<k&&nums[j-1]==nums[j]) j++;
                }
            }
            
        }
        return ans;
    }
};