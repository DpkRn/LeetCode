class Solution {
public:
    
    void mergeSort(vector<int> &nums,int l, int  r){
        if(l>=r) return;
        int m=(l+r)>>1;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        int l1=l; int l2=m+1;
        int i=0;
        vector<int> temp(r-l+1);
        while(l1<=m&&l2<=r){
            if(nums[l1]<nums[l2]){
                temp[i++]=nums[l1++];
            }else temp[i++]=nums[l2++];
        }

        while(l1<=m) temp[i++]=nums[l1++];
        while(l2<=r) temp[i++]=nums[l2++];

        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};