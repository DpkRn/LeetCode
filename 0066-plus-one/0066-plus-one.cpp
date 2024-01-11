class Solution {
public:
    int fun(vector<int> &digits,int i){
        
        if(i==digits.size()) {
            return 1;}
        int carry=fun(digits,i+1);
            int n=digits[i]+carry;
            digits[i]=n%10;
            return n/10;
     }
    vector<int> plusOne(vector<int>& digits) {
        int carry=fun(digits,0);
        if(carry==1){
            reverse(digits.begin(),digits.end());
            digits.push_back(carry);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};