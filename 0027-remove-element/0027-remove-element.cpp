class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r=nums.size()-1;
        int l=0;
        
        while(l<=r){
            if(nums[l]==val){
                swap(nums[l],nums[r--]);
                continue;
            }
            l++;
        }
        return r+1;
    }
};