class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
       map<int,int> mp;
        for(int i=0;i<n;i++){
            int rem=bills[i]-5;
            
                switch(rem){
                case 5:
                    if(mp[5]>=1){
                        rem-=5;
                        mp[5]--;
                    }
                    else return 0;
                break;
                case 15:
                    if(mp[10]>=1&&mp[5]>=1||mp[5]>=3){
                        if(mp[10]>=1){
                            mp[10]--; 
                            mp[5]--;
                        }else{   
                            mp[5]-=3;
                        }
                    }else return false;
                
                break;
              }
            
            mp[bills[i]]++;
        }
            
        
        return true;
    }
};