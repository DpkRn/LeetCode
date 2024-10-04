class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
          int n=skill.size();
        int noOfGroups=n/2;
        int sum=accumulate(skill.begin(),skill.end(),0);
        if(sum%noOfGroups!=0) return -1;
        int k=sum/noOfGroups;
        sort(skill.begin(),skill.end());
        long long ans=0;
        for(int i=0;i<n/2;i++){
            if(skill[i]+skill[n-1-i]!=k) return -1 ;
            else ans+=(1ll*skill[i]*skill[n-i-1]);   
        }
        return ans;
    }
};

/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int noOfGroups=n/2;
        int sum=accumulate(skill.begin(),skill.end(),0);
        if(sum%noOfGroups!=0) return -1;
        int k=sum/noOfGroups;
        unordered_map<int,int> mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp[k-skill[i]]>0){
                ans+=(k-skill[i])*1ll*skill[i];
                mp[k-skill[i]]--;;
            }else{
                mp[skill[i]]++;
            }
        }
        for(auto [_,it]:mp){
            if(it>0) return -1;
        }
        return ans;


        
    }
};

*/