class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        stack<pair<string,int>> st;
        int i=0;
        while(i<n){
             
            if(isupper(formula[i])){
               char ch=formula[i];
               string str="";
               str+=ch;
               i++;
                while(i<n&&islower(formula[i])) {
                    char ch=formula[i];
                    str+=ch;
                    i++;
                }
                string digits="";
                while(i<n&&isdigit(formula[i])){
                    char ch=formula[i];
                    digits+=ch;
                    i++;
                }
                if(digits=="") digits="1";
                int count=stoi(digits);
                cout<<str<<" "<<count<<endl;
                st.push({str,count});
            }else if(formula[i]=='('){
               st.push({"(",-1});
               i++;
            }else if(formula[i]==')'){
                i++;
                string digits="";
                while(i<n&&isdigit(formula[i])){
                    char ch=formula[i];
                    digits+=ch;
                    i++;
                }
                if(digits=="") digits="1";
                int count = stoi(digits);
                vector<pair<string,int>> temp;
                while(st.top().first!="("){
                    temp.push_back({st.top().first,count*st.top().second});
                    st.pop();
                }
                st.pop();
                while(!temp.empty()){
                    st.push({temp.back()});
                    temp.pop_back();
                }

            }
            
        }
        map<string,int> mp;
        while(!st.empty()){
            mp[st.top().first]+=st.top().second;
            st.pop();
        } 

        string str="";
        for(auto it:mp){
            string el=it.first;
            int cnt=it.second;
            string t=cnt!=1?to_string(cnt):"";
            str+=el+t;
        }
        return str;
    }
};