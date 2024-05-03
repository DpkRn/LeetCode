class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> l1,l2;
        string str="";
        stringstream ss(version1);
        while(getline(ss,str,'.')){
            l1.push_back(str);
        }
        stringstream ds(version2);
         while(getline(ds,str,'.')){
            l2.push_back(str);
        }
       
        
        int l=0;
        int r=0;
        while(l<l1.size() and r<l2.size()){
           // cout<<stoi(l1[l])<<"->"<<stoi(l2[r])<<endl;
            if(stoi(l1[l])>stoi(l2[r]))
                return 1;
            else if(stoi(l1[l])<stoi(l2[r]))
                    return -1;
          
         l++; r++;
        }
                    
        while(l<l1.size()){
            if(stoi(l1[l])!=0) return 1;
            l++;
        }
         while(r<l2.size()){
            if(stoi(l2[r])!=0) return -1;
            r++;
        }
        return 0;
        
    }
};