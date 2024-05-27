class Solution {
public:
    vector<int> findLps(string pat){
     //string pat="aabaaac";
    int n=pat.size();
    int len=0;
    vector<int> lps(n,0);
    lps[0]=0;
    int i=1;
    while(i<n){
        if(pat[len]==pat[i]){
            len++;
            lps[i]=len; i++; 
        }else{  
            //if not equal then set len to upto matching(previous) longest prefix same as suffix;  
            if(len!=0){
                len=lps[len-1];
                continue;
            }
            //else if j==0 then  increase i 
            i++;
        }
    }
    return lps;
 }


 vector<int> findIndex(string t,string p){
    vector<int> lps=findLps(p);
    vector<int> ans;
    int n=t.size(),m=p.size();
    int i=0,j=0;
    while(i<n){
        if(t[i]==p[j]){
            i++;j++;
        }else{
            if(j!=0){
                j=lps[j-1];
                continue;
            }
            i++;
        }
       
        if(j==m) {
            ans.push_back(i-m);
            j=lps[j-1];
        }
    }
     return ans;
 }
 
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aInd,bInd;
        int n1=a.size();
        int n2=b.size();
        aInd=findIndex(s,a);
        bInd=findIndex(s,b);
      
        if(bInd.size()==0||aInd.size()==0) return {};
        vector<int> ans;
        for(auto it:aInd){
            int ind=lower_bound(bInd.begin(),bInd.end(),it)-bInd.begin();
            if(ind!=bInd.size()&&abs(bInd[ind]-it)<=k){ ans.push_back(it); continue; }
            if(ind!=0&&abs(bInd[ind-1]-it)<=k) ans.push_back(it);
            
        }
        return ans;
    }
};