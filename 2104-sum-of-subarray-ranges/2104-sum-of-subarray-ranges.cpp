class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
       // sum of all the smallest element contributing to subarray
       vector<int> nse(n,n);
        stack<int> st;
        //finding next Smaller Element
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
        vector<long long> sSum(n+1,0);
        //getSum of all smaller element contributing to each subarray
        long long tSSum=0;
        for(int i=n-1;i>=0;i--){
            sSum[i]=(1ll*nse[i]-i)*nums[i]+sSum[nse[i]];
            tSSum+=sSum[i];
        }
         
          // sum of all the smallest element contributing to subarray
       vector<int> nle(n,n);
         while(!st.empty()) st.pop();
        //finding next Smaller Element
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()){
                nle[i]=st.top();
            }
            st.push(i);
        }
        vector<long long> lSum(n+1,0);
        //getSum of all smaller element contributing to each subarray
        long long tLSum=0;
        for(int i=n-1;i>=0;i--){
            lSum[i]=(1ll*nle[i]-i)*nums[i]+lSum[nle[i]];
            tLSum+=lSum[i];
        }
         
        return tLSum-tSSum;
        
        
        
    }
};