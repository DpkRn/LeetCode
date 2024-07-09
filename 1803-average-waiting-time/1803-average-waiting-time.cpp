class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int end=customers[0][0];
        int n=customers.size();
        double wait=0;
        for(auto it:customers){
            int st=it[0];
            if(end<it[0])
            end=it[0];
            end=end+it[1];
            cout<<end-st<<" ";
            wait+=(end-st);
        }
        return wait/n;
    }
};