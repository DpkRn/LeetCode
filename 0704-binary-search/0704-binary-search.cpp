class Solution {
public:
    // int binarySearch(vector<int>& nums,int low,int high, int target){
    //     if(low>high) return -1;
    //     int mid=low-(low-high)/2;
    //     if(nums[mid]==target) return mid;
    //     else if(nums[mid]>target) return binarySearch(nums,low,mid-1,target);
    //     else 
    //     return binarySearch(nums,mid+1,high,target);
    // }
    int search(vector<int>& nums, int target) {
       // return binarySearch(nums,0,nums.size()-1,target);
       int l=0;int h=nums.size()-1;
      
       while(l<=h){
           int m=l-(l-h)/2;
           if(nums[m]>target){
               h=m-1;
           }else if(nums[m]<target){
               l=m+1;
           }else
            return m;
       }
       return -1;
    }
};