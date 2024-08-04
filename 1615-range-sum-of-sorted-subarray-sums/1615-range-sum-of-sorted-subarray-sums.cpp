#define M 1000000007
typedef pair<int,int> P;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        long long result=0;
        for(int cnt=1;cnt<=right;cnt++){
            auto [sum,idx]=pq.top();
            pq.pop();
            if(cnt>=left){
               cout<<sum<<" "<<idx<<endl;
               result=(result+sum)%M;
            }
            if(idx+1<n) pq.push({sum+nums[idx+1],idx+1});
        }
        return result;
    }
};