class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> next(n),prev(n);
        cout<<next.size();  
        for(int i=n-1;i>=0;i--){
            next[i]= i==n-1?height[i]:max(height[i],next[i+1]);
        }
        for(int i=0;i<n;i++){
            prev[i]= i==0?height[i]:max(height[i],prev[i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(next[i],prev[i])-height[i]);
        }
        return ans;

    }
};