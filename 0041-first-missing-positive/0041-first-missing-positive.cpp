class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0) nums[i]=nums.size()+1;
        }
        int i=0; 
        while(i<nums.size()){
            int correctInd=nums[i]-1;
            if(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[correctInd]){
                swap(nums[i],nums[correctInd]);
            }
            else
                i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};