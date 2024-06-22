class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,n=customers.size();
        
        //initial satifaction
        for(int i=0;i<n;i++) sum+=grumpy[i]==0?customers[i]:0;
        
        //search maximum satification while grumpy
        int l=0;
        int maxi=0;
        int gsum=0;
        for(int i=0;i<n;i++){
            gsum+=grumpy[i]==1?customers[i]:0;
            if(i-l+1>minutes){
                sum-=grumpy[l]==1?customers[l]:0;
                l++;
            }
            if(sum+gsum>maxi){
                maxi=sum+gsum; 
            }
        }    
     return maxi;
    }
};