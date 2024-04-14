class Solution {
public:
    int trap(vector<int>& height) {
       
        int n=height.size();
        
        int left[n];int right[n];
        left[0]=height[0];
         right[n-1]=height[n-1];
        //finding leftgreatest and right greatest of each index
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
            right[n-i-1]=max(right[n-i],height[n-1-i]);
        }
      
        for(auto x:left){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:right){
            cout<<x<<" ";
        }
        cout<<endl;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(left[i],right[i])-height[i];
        }
       
        return sum;
    }
};