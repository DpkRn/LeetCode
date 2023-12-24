class Solution {
    int getPair(vector<int>& potions,int num,long long success){
        int low=0;int high=potions.size()-1;
        while(low<=high){
            int mid=low-(low-high)/2;
            if(1ll*potions[mid]*num>=success)
                high=mid-1;
            else low=mid+1;
        }
        return potions.size()-low;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int s=spells.size();
       // int p=postions.size();
        vector<int> ans;
        for(int i=0;i<s;i++){
            ans.push_back(getPair(potions,spells[i],success));
        }
        return ans;
    }
};