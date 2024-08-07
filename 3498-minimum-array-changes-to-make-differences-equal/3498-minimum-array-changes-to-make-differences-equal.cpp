class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        vector<int> v;
        for(int i=0;i<n/2;i++){
            int a=nums[i],b=nums[n-i-1];
            freq[abs(b-a)]++;
            int maxChange=max(max(a,b),k-min(a,b));//either minm->0 then x<=max or max->k i.0 x<=k-min(a,b)
            // then only 1+ otherwize we need to decr minm and increase max to get in range i.e 2+
            v.push_back(maxChange);
        }
        sort(v.begin(),v.end());
        int ans=1e9;
        for(auto it:freq){
            int x=it.first; int cnt=it.second;
            int ind=lower_bound(v.begin(),v.end(),x)-v.begin();
            ans=min(ans,n/2-cnt+(ind));
        }
        return ans;
    }
};

/*
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

*/