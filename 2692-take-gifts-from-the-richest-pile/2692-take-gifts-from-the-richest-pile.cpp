class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
         long long ans=0;
        for(auto it:gifts){
            pq.push(it);
            ans+=it;
        }

       
        while(!pq.empty()&&k>0){
            int top=pq.top();
            ans-=top;
            int t=sqrt(top);
            pq.pop();
            pq.push(t);
            ans+=t;
            k--;
        }
        // while(!pq.empty()){
        //     ans+=pq.top();
        //     pq.pop();
        // }
        return ans;

    }
};