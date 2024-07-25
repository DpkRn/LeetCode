class Solution {
public:
long long cnt=0;
void getCount(vector<int>&arr,int l,int m,int r){  
    int j=m+1;
    for(int i=l;i<=m;i++){ 
        while(j<=r&&arr[i]>1ll*2*arr[j]) j++;
        cnt+=(j-m-1);
    }
}
void mergeS(vector<int> &arr,int l, int m, int r){
    
    int l1=l; int l2=m+1;
    
    
    vector<int> temp;
    while(l1<=m&&l2<=r){
        if(arr[l1]>arr[l2]){
            temp.push_back(arr[l2++]);
        }else{
            temp.push_back(arr[l1++]);
        }
    }
    while(l1<=m) temp.push_back(arr[l1++]); 
    while(l2<=r) temp.push_back(arr[l2++]);
    
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
    
}

void merge(vector<int> &arr, int l, int r){
    if(l==r) return ;
    int m=(l+r)/2;
    merge(arr,l,m);
    merge(arr,m+1,r);
    getCount(arr,l,m,r);
    mergeS(arr,l,m,r);
    
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        merge(nums,0,n-1);
        return cnt;
    }
};