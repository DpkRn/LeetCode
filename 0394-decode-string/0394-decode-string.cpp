class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        string temp=""; int c=0;
        stack<int> freq; stack<string> dec;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                c=c*10+(s[i]-'0');
            }else if(isalpha(s[i])){
                temp+=s[i];
            }else if(s[i]=='['){
                dec.push(temp);
                freq.push(c);
                temp=""; c=0;
            }else if(s[i]==']'){
                string curr="";
                for(int j=0;j<freq.top();j++){
                    curr+=temp;
                }
                temp=dec.top()+curr;
                dec.pop(); freq.pop();
            }
        }
        return temp;
    }
};