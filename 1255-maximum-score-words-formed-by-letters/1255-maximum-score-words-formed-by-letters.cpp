class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        unordered_map<char,int> mp;
        for(int i=0;i<letters.size();i++){
            mp[letters[i]]++;
        }
        int maxi=0;
        for(int mask=0;mask<(1<<n);mask++){
            int s=0;
            unordered_map<char,int> temp=mp;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                  
                    for(int j=0;j<words[i].size();j++){
                        if(temp[words[i][j]]>0){
                            s+=score[words[i][j]-'a'];
                            temp[words[i][j]]--;
                        }else{
                            s=-1e9;
                            break;
                        }
                        
                    }
                }
            }
            
            maxi=max(s,maxi);
        }
        return maxi;
    }
};