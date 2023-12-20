class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        int l=0,r=0;
        vector<int> ans;
        while(l<n1&&r<n2){
            if(nums1[l]<=nums2[r])
            ans.push_back(nums1[l++]);
            else
            ans.push_back(nums2[r++]);
        }        
        while(l<n1){
            ans.push_back(nums1[l++]);
        }
        while(r<n2){
           ans.push_back(nums2[r++]);
        } 
        if(n%2==1){
            return 1ll*ans[n/2];
        }
        else{
            return (double)(1ll*ans[n/2]+ 1ll*ans[n/2-1])/2.0;
        }
    }
};