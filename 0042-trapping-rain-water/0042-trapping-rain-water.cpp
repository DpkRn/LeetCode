class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left[n],right[n];
        for(int i=0;i<n;i++){
            left[i]=i-1>=0?max(left[i-1],height[i]):height[0];
            right[n-1-i]=n-i<n?max(right[n-i],height[n-1-i]):height[n-1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};