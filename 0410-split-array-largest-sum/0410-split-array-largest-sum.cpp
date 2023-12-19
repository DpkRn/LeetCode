#include<bits/stdc++.h>
class Solution {
    int noOfSubArr(vector<int>&nums,int sum){
        int cntArr=1;
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            if(totalSum+nums[i]<=sum){
                totalSum+=nums[i];
            }else{
                cntArr++;
                totalSum=nums[i];
            }
        }
        return cntArr;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)>>1;
            if(noOfSubArr(nums,mid)<=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};