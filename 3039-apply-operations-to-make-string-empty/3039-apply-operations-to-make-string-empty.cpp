class Solution {
public:
    string lastNonEmptyString(string s) {
         //cnt all the maximum freq and make the string of character of maximum frequency in given order;
        vector<int> freq(26,0);
        int maxi=-1e9;
        for(auto c:s) {
            freq[c-'a']++;
            maxi=max(maxi,freq[c-'a']);
        }
        if(maxi==1) return s;
        string str="";
        for(int i=s.size()-1;i>=0;i--){
            if(freq[s[i]-'a']==maxi) {
                str+=s[i];
                freq[s[i]-'a']=-1; //set as minimum so character in ans not repeated
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
/*
class Solution {
public:
    string lastNonEmptyString(string s) {
        //cnt all the maximum freq and make the string of character of maximum frequency in given order;
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
*/