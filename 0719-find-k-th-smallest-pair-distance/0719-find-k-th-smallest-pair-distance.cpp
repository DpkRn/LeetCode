class Solution {
public:
//     int getLessThanK(auto &nums,int k){
//         int n=nums.size();
        
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             int l=i+1; int r=n-1;
//             while(l<=r){
//                 int mid=(l+(r-l)/2);
//                 if(abs(nums[mid]-nums[i])>k){
//                     r=mid-1;
//                 }else{
//                     l=mid+1;
//                 }
//             }
//             cnt=(cnt+(l-(i+1))%(int)(1e9+7));
//         }
//         return cnt;
//     }
    int getLessThanK(auto &nums,int k){
        int n=nums.size();
        
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>k) j++;
            if(nums[i]-nums[j]<=k) cnt+=(i-j);
        }
        cout<<cnt<<" ";
        return cnt;
    }
    
    
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=1e9;
        for(auto p=0;p<n-1;p++){
            mini=min(mini,nums[p+1]-nums[p]);
        }
       
        
        int l=mini; int r=abs(nums[0]-nums[n-1]);
       
        while(l<=r){
            int mid=l+(r-l)/2;
            int cnt=getLessThanK(nums,mid);
            if(cnt>=k){
                r=mid-1;
            }else{ 
                l=mid+1;
            }
        }
        return l;
        
        
    }
};