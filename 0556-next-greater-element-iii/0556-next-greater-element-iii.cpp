class Solution {
public:
    string str="";
    int nextGreaterElement(int n) {
      string str=to_string(n);
        int ind=-1;
        int size=str.size();
        for(int i=size-2;i>=0;i--){
            if(str[i]<str[i+1]){
                ind=i; break;
            }
        }
        if(ind==-1) return -1;
    
        for(int i=size-1;i>ind;i--){
            if(str[i]>str[ind]){

                swap(str[i],str[ind]);
                break;
            }
        }
        reverse(str.begin()+ind+1,str.end());

        long long ans=stol(str);
        if(ans>INT_MAX){
            return -1;
        }
        
        return ans;
    }
};