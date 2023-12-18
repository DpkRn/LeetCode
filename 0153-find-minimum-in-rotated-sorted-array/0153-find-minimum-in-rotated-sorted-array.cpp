class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
	int l=0;int h=n-1;
	int mini=INT_MAX;
	while(l<=h){//the array becomes unsorted because of containing small element in right
	//so try to find unsorted array
	 int m=(l+h)/2;
	 mini=min(mini,arr[m]);
	 if(arr[m]>=arr[h])
	   l=m+1;
	 else//if right is sorted then check left 
		h=m-1;
		
	}
	return mini;
    }
};