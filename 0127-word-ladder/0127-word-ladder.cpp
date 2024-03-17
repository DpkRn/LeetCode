class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mp;
        for(auto str:wordList){
            mp[str]=true;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        mp[beginWord]=false;
        while(!q.empty()){
            string currStr=q.front().first;
            int level=q.front().second;
            cout<<currStr<<" ";
            q.pop();
            if(currStr==endWord) return level;
            for(int i=0;i<currStr.size();i++){
                string temp=currStr;
                for(int j=0;j<26;j++){
                    temp[i]=(char)j+97;
                    if(mp[temp]==true){
                        q.push({temp,level+1});
                        mp[temp]=false;
                    }
                }  
            }
        }
        return 0;
        
    }
};