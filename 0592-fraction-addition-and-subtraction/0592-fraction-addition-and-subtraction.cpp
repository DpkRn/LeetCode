class Solution {
public:
    string fractionAddition(string exp) {
        vector<int> nmn,dnm;
        int n=exp.size();
        if(n==0) return "";
        string str="";
        for(int i=0;i<n;i++){
            if(str.size()!=0&&exp[i]=='/'){

                int num=stoi(str);
                
                nmn.push_back(num);
                str="";
                continue;
            }
            if(str.size()!=0&&(exp[i]=='+'||exp[i]=='-')){
               int num=stoi(str);
                dnm.push_back(num);
                str=""; 
            }
            str+=exp[i];

        }
        int num=stoi(str);
        dnm.push_back(num);
        int l=1;
        for(auto it:dnm) l=lcm(l,it);
        int res=0;
        for(int i=0;i<nmn.size();i++){
            int q=l/dnm[i];
            res+=(q*nmn[i]);
        }
        if(res==0) return "0/1";
        string sign=(res<0?"-":"+");
        res=abs(res);
        l=abs(l);
        int gcd=__gcd(res,l);
        while(gcd!=1){
            
            res/=gcd;
            l/=gcd;
            gcd=__gcd(l,res);
        }
        string resn=to_string(res);
        string resd=to_string(l);
        string ans=resn+"/"+resd;
        return sign=="-"?"-"+ans:ans;
    }
};