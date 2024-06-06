class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n=hand.size();
        int k=groupSize;
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
       
        for(int i=0;i<n;i++) mp[hand[i]]++;
       
        int i=0;
        vector<vector<int>> ans;
        while(i<n){
            vector<int> temp;
            if(mp[hand[i]]==0){ i++; continue ;}
            for(int j=0;j<k;j++){
                int num=hand[i]+j;
                if(mp[num]==0)
                    return false;
                temp.push_back(num);
                mp[num]--;
            }
            ans.push_back(temp);
            i++;
        }
        for(auto it:ans){
            for(auto itr:it) cout<<itr<<" "; cout<<endl;
        }
        return true;
        
    }
};