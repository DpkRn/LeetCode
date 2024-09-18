class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        string str="";
        long long s=0;
        for(auto it:nums) {
            str+=to_string(it);
            s+=it;
        }
        if(s==0) return "0";
        return str;
    }
};