class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        int l=0,r=0;
        int low=INT_MIN,high=INT_MIN;
        int cnt=0;int flag=false;
        int k=(n/2);
        while(l<n1&&r<n2&&flag==false){
            if(nums1[l]<=nums2[r]){
                cnt++;
                if(cnt==k){
                    low=nums1[l];
                } 
                if(cnt==k+1) {high=nums1[l];  flag=true;}
                l++;
               
            }
            else{
            
                 cnt++;
                if(cnt==k){
                    low=nums2[r];
                } 
                if(cnt==k+1) {high=nums2[r]; flag=true;}
                r++;
            }
        }        
        while(l<n1&&flag==false){
            
             cnt++;
                if(cnt==k){
                    low=nums1[l];
                } 
                if(cnt==k+1) {high=nums1[l];  flag=true;}
                l++;
               
        }
        while(r<n2&&flag==false){
           
             cnt++;
                if(cnt==k){
                    low=nums2[r];
                } 
                if(cnt==k+1) {high=nums2[r]; flag=true;}
                r++;
        } 
        if(n%2==1){
            return 1ll*high;
        }
        else{
            return (double)(1ll*low+ 1ll*high)/2.0;
        }
    }
};