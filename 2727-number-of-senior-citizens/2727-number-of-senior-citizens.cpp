class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto detail:details){
            if(stoi(detail.substr(11,2))>60) {
                cnt++;
                cout<<detail.substr(11,2)<<endl;
            }
        }
        return cnt;
    }
};