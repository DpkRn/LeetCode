class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,string> mp;
        int n=dictionary.size();
        stringstream ss(sentence);
        vector<string> st;
        string temp;
        while(ss>>temp){
            st.push_back(temp);
        }
        
        for(int i=0;i<n;i++){
            int sz=dictionary[i].size();
            for(auto str:st){
                if(str.size()<sz) continue;
                string word(str.begin(),str.begin()+sz);
                if(word==dictionary[i]){
                    if(mp.find(str)==mp.end()||mp[str].size()>dictionary[i].size()){
                        mp[str]=dictionary[i];
                    } 
                }
            }
        }
        
        string ans="";
        for(auto str:st){
            if(mp.find(str)!=mp.end()){
                ans+=mp[str];
                
            }else ans+=str;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};