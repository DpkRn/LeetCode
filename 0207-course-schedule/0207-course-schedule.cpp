class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //making adjency matrix
        if(!prerequisites.size()) return true;
        vector<int> adj[numCourses];
         //indegree of each node
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        //for(auto it:indegree) cout<<it<<" ";
        //topo sort
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> vec;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vec.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
        }
        return numCourses==vec.size();
    

    }
};