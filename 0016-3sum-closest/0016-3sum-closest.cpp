class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int mini=1e9;
        int ans=1e9;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                for(int next=i+1;next<n;next++){
                    int sum=nums[prev]+nums[i]+nums[next];
                    int dist=abs(sum-target);
                    if(dist<mini){
                        mini=dist;
                        ans=sum;
                        
                    }
                }
            }
            
        }
        return ans;
    }
};