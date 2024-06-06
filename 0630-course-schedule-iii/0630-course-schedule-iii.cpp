class Solution {
public:
    static bool com(vector<int> a,vector<int> b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),com);
        priority_queue<int> pq;
        int n=courses.size(); 
        int sum=0;
        int cnt=0;
        for(auto course:courses){
           // cout<<course[0]<<" "<<course[1]<<endl;
            if(course[0]<=course[1]){
                if(sum+course[0]<=course[1]){
                    pq.push(course[0]);
                    sum=sum+course[0];
                    cnt++;
                }else{
                    if(pq.top()>course[0]){
                        sum-=pq.top();
                        pq.pop();
                        sum+=course[0];
                        pq.push(course[0]);                        
                    }
                }  
            }

        }
        return cnt;
    }
};