class Solution {
    //array
public:
    int removeDuplicates(vector<int>& nums) {
        int flag=INT_MAX;
        int m=0; int n=nums.size();
        for(int i=0;i<n;i++){
            if(flag!=nums[i]){
                nums[m]=nums[i];
                flag=nums[m];
                m++;
            }
        }
        return m;
    }
};