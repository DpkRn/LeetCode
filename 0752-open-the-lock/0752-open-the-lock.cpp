class Solution {
public:
    
    map<string,int> dead; 
    char turnRight(char ch){
         return ch=='9'?'0':ch+1;
    }
    char turnLeft(char ch){
        return ch=='0'?'9':ch-1;      
    }
    vector<string> getNextLevel(string str){
        vector<string> temp;
        string original=str;
        
        for(int i=0;i<4;i++){
            str[i]=turnLeft(original[i]);
            temp.push_back(str);
            str=original;
            str[i]=turnRight(original[i]);
            temp.push_back(str);
            str=original;
        }
        return temp;
    }
        
    int openLock(vector<string>& deadends, string target) {

        for(auto it: deadends) dead[it]=1;
        
        queue<pair<vector<string>,int>> q;
        q.push({{"0000"},0});
       
        while(!q.empty()){
           vector<string> currVec=q.front().first;
           int lvl=q.front().second;
           q.pop();
            for(int i=0;i<currVec.size();i++){
                if(currVec[i]==target) return lvl;
                if(!dead[currVec[i]]){
                    cout<<currVec[i]<<" ";
                    dead[currVec[i]]=1;
                    vector<string> temp=getNextLevel(currVec[i]);
                    q.push({temp,lvl+1});
                }
            }
            cout<<lvl<<endl;
            
        }
        return -1;
    }
};