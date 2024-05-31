class Solution {
public:
    //by staying at one index calculate prefix and store the result on stayed index
    //if its zero that means all index between i and j can make value 0
    //because a and b are countinues index xor so if a==b that means it will also be a^b=0 so that 
    //instead of checking all the indices only cheking from i to j which is given me 0; and cnt all the indices beetween  i and j
    int countTriplets(vector<int>& arr) {
        int sz=arr.size();
        int ans=0;
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                arr[i]=arr[i]^arr[j];
                if(arr[i]==0)
                {
                   ans+=j-i;
                }
            }
        }
        return ans;
        
    }
};