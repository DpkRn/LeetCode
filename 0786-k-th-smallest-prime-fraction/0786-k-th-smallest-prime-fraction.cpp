class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,pair<int,int>>> pq;
        int n=arr.size();
        for(auto p=0;p<n;p++){
            for(int q=p+1;q<n;q++){
                
                pq.push({(float)arr[p]/arr[q],{arr[p],arr[q]}});
                if(pq.size()>k){
                    pq.pop();
                }
                
            }
        }
        cout<<pq.top().first;
        int p=pq.top().second.first;
        int q=pq.top().second.second;
        return {p,q};
    }
};