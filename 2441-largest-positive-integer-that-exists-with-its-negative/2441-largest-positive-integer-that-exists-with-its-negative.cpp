class Solution {
    //O(NLOGN)
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=-1;
        int i=0,j=n-1;
        while(i<j&&nums[i]<nums[j]){
            if(abs(nums[i])==nums[j])
                return nums[j];
            else if(abs(nums[i])>nums[j]) i++;
            else j--; 
        }
        return maxi;
    }
};
/*
O(N^2)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi=-1;
        for(auto it:nums){
            if(it<0){
                 for(auto op:nums){
                    if(op>0&&abs(it)==op){
                        maxi=max(op,maxi);
                    }
                 }
            }
           
        }
        
        return maxi;
    }
};
*/