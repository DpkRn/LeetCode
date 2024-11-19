class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while(n>1){
            // cout<<n<<" ";
            if(st.contains(n)) return false;
            st.insert(n);
            int sum=0;
            while(n>0){
                int lstD=n%10;
                cout<<lstD<<" ";
                sum+=(lstD*lstD);
                n/=10;
            }
           
            n=sum;
        }
        return true;
    }
};