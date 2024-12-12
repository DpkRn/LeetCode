class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto it:gifts){
            pq.push(it);
        }

        long long ans=0;
        while(!pq.empty()&&k>0){
            int t=sqrt(pq.top());
            pq.pop();
            pq.push(t);
            k--;
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;

    }
};