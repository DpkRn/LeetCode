class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0; int high=n1;
        int n=n1+n2;
        int leftArr=n/2;
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=leftArr-mid1;
            int l1=mid1-1<0?INT_MIN:nums1[mid1-1];
            int l2=mid2-1<0?INT_MIN:nums2[mid2-1];
            int r1=mid1<n1?nums1[mid1]:INT_MAX;
            int r2=mid2<n2?nums2[mid2]:INT_MAX;
            
            if(l1<=r2&&l2<=r1){
                if(n%2==0) return (double)(max(l1,l2)+min(r1,r2))/2.0;
                else return min(r1,r2);
            }else if(l1>r2){
                high=mid1-1;
            }else {
                low=mid1+1;
            }
            
        }
        return 0;
    }
};