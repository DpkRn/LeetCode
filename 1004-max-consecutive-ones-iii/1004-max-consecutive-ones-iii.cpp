class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0,flip=0,l=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
              if(nums[i]==0) flip++;
                
               while(flip>k){
                   if(nums[l]==0) flip--;
                   l++;
               } 
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};