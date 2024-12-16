#define P pair<double,int> 
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<P> pq;
        int i=0;
        for(auto it:classes){
            double profit=(((double)it[0]+1)/((double)it[1]+1))-((double)it[0]/it[1]);
            pq.push({profit,i});
            i++;
        }
        while(extraStudents--){
            int idx=pq.top().second;
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double newProfit=(((double)classes[idx][0]+1)/(classes[idx][1]+1))-((double)classes[idx][0]/classes[idx][1]);
            pq.push({newProfit,idx});
        }

        double ans=0;
        for(auto it:classes){
            ans+=((double)it[0]/it[1]);
        }
        return ans/n;

    }
};