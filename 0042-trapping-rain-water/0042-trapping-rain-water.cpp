class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n=height.size();
        st.push(height[0]);
        int left[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            if(st.top()>=height[i]){
                left[i]=st.top();
            }
            else{
                st.push(height[i]);
                left[i]=height[i];
            }
        }
        while(!st.empty()) st.pop();
        
        st.push(height[n-1]);
        int right[n];
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(st.top()>height[i]){
                right[i]=st.top();
            }
            else{
                st.push(height[i]);
                right[i]=height[i];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(left[i],right[i])-height[i];
        }
        // for(auto it:left) cout<<it<<" "; cout<<endl;
        // for(auto it:right) cout<<it<<" ";
        return sum;
    }
};