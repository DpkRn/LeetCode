class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>> pq;
        for(auto i=0;i<n;i++){
            pq.push({score[i],i});
        }
        
        vector<string> ans(n);
        
        int cnt=1;
        while(!pq.empty()){
            pair<int,int> t=pq.top();
            pq.pop();
           
            if(cnt==1){
                ans[t.second]="Gold Medal";
            }else
            if(cnt==2){
                ans[t.second]="Silver Medal";
            }else
            if(cnt==3){
                ans[t.second]="Bronze Medal";
            }else  ans[t.second]=to_string(cnt);
           cnt++;
        }
        return ans;
    }
};