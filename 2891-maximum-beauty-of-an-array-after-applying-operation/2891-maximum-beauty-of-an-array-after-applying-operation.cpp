class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        //suppose two no is (x,y) and i want to make equal by increasing and decreasing to k lets x<y then 
        //it would be equal only its interval (x-k,x+k) overlaps with (y-k,y+k)
        //condition to overlap (x+k)>=(y-k)
        //y<=x+2*k
        //and apply the merge interval below technique

        int n=nums.size();
        sort(begin(nums),end(nums));
       
        int ans=0;
        for(int i=0;i<n;i++){
            int target=nums[i]+2*k;
            int ind=upper_bound(begin(nums),end(nums),target)-nums.begin();
            ans=max(ans,ind-i);
        }
        return ans;        
    }
};

/*
class Solution {
public:
//using interval method
  int n=nums.size();
        sort(begin(nums),end(nums));
        deque<int> dq;
        int ans=0;
        for(auto it:nums){
            while(!dq.empty()&&!(it<=dq.front()+2*k)) dq.pop_front();
            dq.push_back(it);
            ans=max(ans,(int)dq.size());

        }
        return ans;        


//using interval
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> deq;
        vector<pair<int,int>> intervals;
        for(auto it:nums){
            intervals.push_back({it-k,it+k});
        }
        sort(begin(intervals),end(intervals));

        int ans=0;
        for(auto interval:intervals){
            while(!deq.empty()&&deq.front().second<interval.first){
                deq.pop_front();
            }
            deq.push_back({interval});
            ans=max(ans,(int)deq.size());
        }
        return ans;
    }
};
*/