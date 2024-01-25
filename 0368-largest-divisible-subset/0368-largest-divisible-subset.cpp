class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int maxi=1;
        int lastInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastInd=i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd=hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        return ans;
      
    }
};
/*
vector<int> f(int ind,int prev,int n,vector<int> &arr){
    if(ind==n) return {};
    vector<int> nottake=f(ind+1,prev,n,arr);
    vector<int> take={};
    if (prev == -1 || arr[ind] % arr[prev] == 0) {
       take=f(ind+1,ind,n,arr);
      take.push_back(arr[ind]);
     
    }
    if(take.size()>nottake.size())
    return take;
    return nottake;

}
vector<int> divisibleSet(vector<int> &arr)
{  int n=arr.size();
    sort(arr.begin(),arr.end());
    return f(0, -1, n, arr);
}
*/