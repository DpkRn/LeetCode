#define ll long long
class Solution {
public:
    string addOne(string s){
        reverse(s.begin(),s.end());
        char carry='1';
        string str="";
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]=='1'&&carry=='0')
                {str.push_back('1'); carry='0';}
            else if(s[i]=='1'&&carry=='1'){ str.push_back('0'); carry='1';}
            else if(s[i]=='0'&&carry=='0') {str.push_back('0'); carry='0';}
            else if(s[i]=='0'&&carry=='1') {str.push_back('1'); carry='0';}
            i++;
        }
        if(carry=='1') str.push_back('1');
         reverse(str.begin(),str.end());
        //cout<<str<<" ";
        return str;
       
    }
    int numSteps(string s) {
        int n=s.size();
       
       
        int steps=0;
        while(s!="1"){
            int i=s.size()-1;
            steps++;
            if(s[i]=='1'){
                s=addOne(s);
            }else{
                s.pop_back();
               
            }
             cout<<s<<" ";
            
        }
        
      
        return steps;
    }
};