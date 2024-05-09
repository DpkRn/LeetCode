class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        int n=happiness.size();
        for(auto it:happiness){
            pq.push(it);
        }
        long long decr=0;
        long long  h=0;
        while(k--){
            int top=pq.top();
            pq.pop();
            if(top-decr>=0)
            h+=(long long)(top-decr);
            decr++;       
        }
        
        return h;
    }
};