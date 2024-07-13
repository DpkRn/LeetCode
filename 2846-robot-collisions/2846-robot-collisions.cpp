class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<char,pair<int,int>>> st;
        vector<vector<int>> v;
        int n=positions.size();
        for(int i=0;i<n;i++){
            v.push_back({positions[i],i});
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<n){
            if(st.empty()||st.top().first=='L'||directions[v[i][1]]=='R'){
                st.push({directions[v[i][1]],{v[i][1],healths[v[i][1]]}});
            }else{
                if(st.top().second.second==healths[v[i][1]]){
                    st.pop(); 
                }else if(st.top().second.second<healths[v[i][1]]){
                    st.pop(); healths[v[i][1]]-=1;
                    continue;
                }else{
                    st.top().second.second-=1;
                }
            }
            i++;
        }
        
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().second.first,st.top().second.second});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int> final;
        for(auto it:ans){
            final.push_back(it.second);
        }
        return final;
    }
};