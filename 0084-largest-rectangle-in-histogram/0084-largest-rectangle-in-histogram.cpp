class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        //creating leftNextSmaller element array
        int leftSmall[n];
        stack<int> st; //help to mentain previous smaller element index
        for(int i=0;i<n;i++){
            while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
            if(st.empty()) leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        //emptying stack to reuse
        while(!st.empty()) st.pop();
        int rightSmall[n];//storing right smaller element ind
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
            if(st.empty()) rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        //now we have range of each index 
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,((rightSmall[i]-leftSmall[i])+1)*h[i]);
        }
        return ans;
    }
};
/*
O(N^2)
  class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,h[j]);
                ans=max((j-i+1)*mini,ans);
            }
        }
        return ans;
        
    }
};
*/

/*
O(N^2) //meet in the middle element
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int l=i;
            while(l>=0&&h[l]>=h[i]) l--;
            int r=i;
            while(r<n&&h[r]>=h[i]) r++;
            int len=(r-l)-1;
            maxi=max(maxi,len*h[i]);            
        }
        return maxi;
    }
};
*/