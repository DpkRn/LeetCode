int find(vector<int> &arr, int val)
{
    int low = 0;
    int high = arr.size()-1;
    
    int mid;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        int curr = arr[mid];
        
        if(curr < val)
        {
            low = mid+1;
            ans = mid;
        }
        
        else if(curr >= val)
            high = mid-1;
    }
    
    return ans+1;
}

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int, int> m;
        vector<int> v;
        
        for(int i=0; i<n/2; ++i)
        {
            m[ abs( nums[i] - nums[n-i-1] ) ]++;
            
            int mx1 = max(k-nums[i], nums[i]); // max for num[i].
            int mx2 = max(k - nums[n-i-1], nums[n-i-1]); // max for num[n-i-1]
            
            int mx = max(mx1, mx2); // Take the maximum among the two
            v.push_back(mx);
        }
        
        sort(v.begin(), v.end());  // sorting required for binary search.
        int ans = 1e9;
        
        for(auto i=m.begin(); i!=m.end(); ++i)
        {
            int val = i->first;
            int fr = i->second;
                
            int a = find(v, val); // binary search
            ans = min(n/2 - fr + a, ans); // keep track of the lowest operation count.
        }
        
        return ans;
    }
};
