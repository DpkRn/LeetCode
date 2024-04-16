class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
      deque<int> q;
        int n=nums.size();
        int i=0;
        for( i=0;i<k;i++){
            while(!q.empty()&&nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
        }        
        vector<int> ans;
        ans.push_back(nums[q.front()]);
        while(i<n){
            if(i-q.front()>=k) q.pop_front();
            while(!q.empty()&&nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            ans.push_back(nums[q.front()]);
            i++;            
        }
       
        return ans;

    }
};
   
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
       deque<int> q;
        int n=nums.size();
        int j=0;
        for( j=0;j<k;j++){
            while(!q.empty()&&nums[q.back()]<nums[j]) q.pop_back();
            q.push_back(j);
        }        
        vector<int> ans(n-k+1);
        ans[0]=nums[q.front()];
        int i=1;
        while(j<n){
            if(q.front()<i) q.pop_front();
            while(!q.empty()&&nums[q.back()]<nums[j]) q.pop_back();
            q.push_back(j);
            ans[i]=nums[q.front()];            
            i++;
            j++;           
        }       
        return ans;
    }
};

*/
/*

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
       deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty()&&i-k==dq.front()) dq.pop_front();
            
            while(!dq.empty()&&nums[dq.back()]<nums[i]) dq.pop_back();
            
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
       
        return ans;
    }
};
*/
/*
//using sliding windows
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> cnt;
        int maxi=INT_MIN;
        vector<int> ans(n-k+1);
        int j=0;
        for( j=0;j<k;j++){
            maxi=max(maxi,nums[j]);
            cnt[nums[j]]++;
        }       
        ans[0]=maxi;
        int i=1;
        while(j<n){            
            if(maxi==nums[i-1]&&cnt[nums[i-1]]==1){
                maxi=*max_element(nums.begin()+i,nums.begin()+j+1); 
            }
            else{
                maxi=max(maxi,nums[j]);
            }
             cnt[nums[i-1]]--;
            cnt[nums[j]]++;
            
            ans[i]=maxi;
            i++; j++;
        }
        return ans;
    }
};
*/
/*
//USING SIGMENT TREE
#define N (int)1e5+2
class Solution {
public:
   
    int tree[4*N];
    void build(vector<int> &nums,int node,int st,int end){
        if(st==end){
            tree[node]=nums[st];
            return;
        }
        int mid=(st+end)>>1;
        build(nums,2*node+1,st,mid);
        build(nums,2*node+2,mid+1,end);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
        
    }
    int query(int node,int st,int end,int l,int r){
        if(l<=st&&end<=r){
            return tree[node];
        }
        if(end<l||r<st) return -1e9;
        int mid=(st+end)>>1;
        return max(query(2*node+1,st,mid,l,r),query(2*node+2,mid+1,end,l,r));
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        build(nums,0,0,n-1);
        vector<int> ans(n-k+1);
        int i=0;
        while(k<=n){
            ans[i]=query(0,0,n-1,i,k-1);
            i++;k++;
        }
        return ans;
    }
};
*/