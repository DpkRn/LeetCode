
/*
class Solution {
public:
    void dfs(int node,vector<int> adj[], vector<int> &vis,stack<int> &st){
       
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
         vis[node]=1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<int> adj[numCourses];
        for(int i=0;i<numCourses;i++){
            for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
            }
        }
        vector<int> vis(numCourses,0);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        if(ans.size()==numCourses) return ans; else return {};
    }
};*/
//using BFS

class Solution {
public:
 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) prerequisites;
        //making adjency matrix
        vector<int> adj[numCourses];
       
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        
        //counting indegree
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        
        //topoSort ordering possible or not
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> courses;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            courses.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
        }
        if(numCourses==courses.size())
        return courses;
        else return {};
    }
};
