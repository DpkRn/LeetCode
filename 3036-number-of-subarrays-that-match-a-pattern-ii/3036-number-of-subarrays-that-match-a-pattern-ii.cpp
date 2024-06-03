class Solution {
public:
    vector<int> LPS(string p){
        int n=p.size();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(p[i]==p[len]){
                len++; lps[i]=len;
                i++;
            }else{
                if(len>0){
                    len=lps[len-1];
                    continue;
                }
                i++;
            }
        }
        return lps;
    }
    int getOcc(string s,string p){
        int n=s.size(),m=p.size();
        int cnt=0;
        vector<int> lps=LPS(p);
        int i=0,j=0;
        while(i<n){
            if(s[i]==p[j]){
                 j++; i++;
            }else{
                if(j>0){
                    j=lps[j-1];
                    continue;
                }
                i++;
            }
            if(j==m){
                cnt++;
                j=j>0?lps[j-1]:0;;
            }
        }
        return cnt;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(),m=pattern.size();
        string s="",p="";
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                s.push_back('a');
            }else if(nums[i]==nums[i+1]) s.push_back('s');
            else s.push_back('d');
            
            if(i<m){
                if(pattern[i]==1) p.push_back('a');
                else if(pattern[i]==0) p.push_back('s');
                else p.push_back('d');
            }
        }
        cout<<s<<" "<<p;
        return getOcc(s,p);
        
    }
};