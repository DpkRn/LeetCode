class Solution {
public:
    int pairsLessThanDist(auto &nums,int m){
        int n=nums.size();
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            int dist=abs(nums[i]-nums[j]);
            while(abs(nums[i]-nums[j]>m)) j++;
            if(abs(nums[i]-nums[j])<=m)
            cnt+=(i-j);
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        int minDist=1e9;
        sort(nums.begin(),nums.end());
        int maxDist=nums[n-1]-nums[0];
        for(int i=1;i<n;i++){
            minDist=min(minDist,nums[i]-nums[i-1]);
        }
        int l=minDist; int r=maxDist;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int pairsCount=pairsLessThanDist(nums,mid);
            if(pairsCount<k){
                l=mid+1;
            }else{
                r=mid-1;
                result=mid;
            }
        }
        return result;
    }
};