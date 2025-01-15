class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        while(num2>0){
            cnt+=(num2&1);
            num2=num2>>1;
        }
        cout<<cnt;
        int result=0;
        for(int i=31;i>=0;i--){
            if((cnt>0)&&(num1&(1<<i))){
                result|=(1<<i);
                cnt--;
            }
        }
        for(int i=0;i<31;i++){
            if((cnt>0)&&((num1>>i)&1)==0){
                result=(result|(1<<i));
                cnt--;
            }
        }
        return result;
        
    }
};