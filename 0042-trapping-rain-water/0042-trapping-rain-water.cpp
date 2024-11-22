class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> next(n),prev(n);
        for(int i=0;i<n;i++){
            prev[i]= i==0?height[i]:max(height[i],prev[i-1]);
            next[n-i-1]= n-i==n?height[n-1-i]:max(height[n-1-i],next[n-i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(next[i],prev[i])-height[i]);
        }
        return ans;

    }
};