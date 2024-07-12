class Solution {
public:
int get(int x, int y, string s1,string s2,string s){
    int n=s.size();
    string str;
    int score=0;
    for(int i=0;i<n;i++){
        if(s[i]==s2[1]&&!str.empty()&&str.back()==s2[0]){
            str.pop_back();
            score+=y;  
        }else{
            str.push_back(s[i]);
        }
    }
    s=str;
    str="";
    n=s.size();
     for(int i=0;i<n;i++){
        if(s[i]==s1[1]&&!str.empty()&&str.back()==s1[0]){
            str.pop_back();
            score+=x;  
        }else{
            str.push_back(s[i]);
        }
    }
    return score;
}
    int maximumGain(string s, int x, int y) {
       
       if(y>x) return get(x,y,"ab","ba",s);
       else return get(y,x,"ba","ab",s);
    }
};