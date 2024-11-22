class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> next(n),prev(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&(st.top()<=height[i])) st.pop();
            next[i]= st.empty()?height[i]:st.top();
           if(st.empty()) st.push(height[i]); 
        }
        
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
           
            while(!st.empty()&&st.top()<=height[i]) st.pop();
            prev[i]= st.empty()?height[i]:st.top();
            if(st.empty())st.push(height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
             cout<<prev[i]<<" ";
            ans+=(min(next[i],prev[i])-height[i]);
        }
        return ans;

    }
};