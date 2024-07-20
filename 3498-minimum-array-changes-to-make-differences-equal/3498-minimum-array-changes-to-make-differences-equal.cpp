class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> left,right;

        for(int i=0;i<n/2;i++){
            left.push_back(nums[i]);
            right.push_back(nums[n-i-1]);
             if(left[i]>right[i]) swap(left[i],right[i]);
        }

       
         vector<int> dp(k+1,0);
         for(int i=0;i<n/2;i++){
            int range=right[i]-left[i];
            dp[range]++;
         }

        priority_queue<pair<int,int>>pq;

         for(int i=0;i<k+1;i++){
            if(dp[i]>0){
                pq.push({dp[i],i});
            }
         }
        int cnt=1e9;;
        while(!pq.empty()){
            int xy=pq.top().second;
            cout<<xy<<" ";
            pq.pop();
            int t=0;
            for(int i=0;i<n/2;i++){
                if(right[i]-left[i]==xy) continue;
                t++;
                if(right[i]-xy<0&&left[i]+xy>k) t++;
            }
           if(cnt<t) return cnt;
            cnt=min(cnt,t);
            cout<<t<<endl;
        }
        return cnt;
    }
};