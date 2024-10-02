class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
       vector<int> ord(n);
       for(int i=0;i<n;i++) ord[i]=i;
       sort(ord.begin(),ord.end(),[&](int a,int b){
          return arr[a]<arr[b];
       });
       for(auto it:ord) cout<<it<<" ";
       vector<int> rank(n);
       rank[ord[0]]=1;
       int r=1;
       for(int i=1;i<n;i++){
        if(arr[ord[i-1]]==arr[ord[i]]) rank[ord[i]]=r;
        else
         rank[ord[i]]=++r;

       }
       return rank;

    }
};

/*
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     set<int> st(arr.begin(),arr.end());
	unordered_map<int,int> m;
	int rank=1;
	for(auto &i: st)  m[i]=rank++;
	for(auto &i: arr) i = m[i];
	return arr;
    }
};
*/