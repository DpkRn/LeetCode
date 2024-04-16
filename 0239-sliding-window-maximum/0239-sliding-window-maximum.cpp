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