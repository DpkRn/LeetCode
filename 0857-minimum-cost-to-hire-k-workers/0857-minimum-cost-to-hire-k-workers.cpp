class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> workers;
        for(int i=0;i<n;i++){
            workers.push_back({wage[i]*1.0/quality[i],quality[i]});
        }
        //paid[j]>=wages[j]
        //paid[j]>=quality[j]*ratio[i]
        //ratio[i]>=ratio[j] to be paid[j]>=wage[j]
        sort(workers.begin(),workers.end());
        priority_queue<int> pq;
        double ans=DBL_MAX;
        int qualitySum=0;
       for(auto worker:workers){
           double ratio=worker.first;
           qualitySum+=worker.second; pq.push(worker.second);
           if(pq.size()>k) { qualitySum-=pq.top(); pq.pop(); }
           if(pq.size()==k) ans=min(ans,ratio*1.0*qualitySum);    
       }     
        return ans;
    }
};