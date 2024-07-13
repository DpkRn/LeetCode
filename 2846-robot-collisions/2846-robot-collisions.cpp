class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<pair<char,int>,int>> st;
        vector<vector<int>> v;

        int n=positions.size();
        for(int i=0;i<n;i++){
            v.push_back({positions[i],i});
        }
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            if(st.empty()||(st.top().first.first==directions[v[i][1]])||(st.top().first.first=='L'&&directions[v[i][1]]=='R')){
                st.push({{directions[v[i][1]],healths[v[i][1]]},v[i][1]});
            }else{
                if(st.top().first.second==healths[v[i][1]]){
                    st.pop();
                }else if(st.top().first.second>healths[v[i][1]]){
                    st.top().first.second-=1;
                }else{
                    while(!st.empty()&&(st.top().first.first=='R'&&directions[v[i][1]]=='L')&&(st.top().first.second<healths[v[i][1]])){
                        st.pop();
                        healths[v[i][1]]-=1;
                    }
                    if(st.empty()&&healths[v[i][1]]>0||st.top().first.first==directions[v[i][1]]||st.top().first.first=='L'&&directions[v[i][1]]=='R'){
                        st.push({{directions[v[i][1]],healths[v[i][1]]},v[i][1]});
                       
                    }else if(st.top().first.second==healths[v[i][1]]){
                            st.pop();
                           
                    }else{
                        st.top().first.second-=1;
                    }
                }
            }
        }

         vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().second,st.top().first.second});
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