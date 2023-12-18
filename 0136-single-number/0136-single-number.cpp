class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int xor1=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            xor1=xor1^nums[i];
        
        return xor1;
        
        
        
        
        
        
//         unordered_map<int,int> mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
            
//          }
//        int ans;
//         for(auto x:mp){
//             if(x.second==1){
//                 ans=x.first;
//                 break;
//             }
                 
//         }
//         return ans;
    }
};