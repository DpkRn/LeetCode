class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> freq(26,0);
        for(auto c:s) freq[c-97]++;
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                pq.push({freq[i],i+97});
            }
        }
        
        unordered_map<char,bool> mp;
        int maxi=pq.top().first;
        while(!pq.empty()){
            int t=pq.top().first; char c=pq.top().second;
            if(t==maxi){
                mp[c]=true;
            }else break;
            pq.pop();
        }
        string ans="";
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(mp.empty()) break;
            if(mp.find(s[i])!=mp.end()){
                ans.push_back(s[i]);
                mp.erase(s[i]);;
            }
                
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};