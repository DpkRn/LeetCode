class Solution {
public:
int get(int x,string s1,string &s){
    int n=s.size();
    string str;
    int score=0;
    for(int i=0;i<n;i++){
        if(s[i]==s1[1]&&!str.empty()&&str.back()==s1[0]){
            str.pop_back();
            score+=x;  
        }else{
            str.push_back(s[i]);
        }
    } 
    s=str;
    return score;
}
    int maximumGain(string s, int x, int y) {
       string s1="ab",s2="ba";
       if(x<y){
        swap(x,y); swap(s1,s2);
       }
       return get(x,s1,s)+get(y,s2,s);
    }
};