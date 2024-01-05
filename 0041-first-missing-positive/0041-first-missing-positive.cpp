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
//The basic approach to fill all the element at its correct possition if the that element will not there in that case the other element which will be arr.size() or greater will take its place 
//after that we can check at which index the right element is not there
//ex: 1 3 4 5
//    1 5 3 4 so in case index+1 will be our ans