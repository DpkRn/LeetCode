class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
	int m=1;
	int r=1;
	int maxi=INT_MIN;
	vector<int> fromLeft;
	vector<int> fromRight;
	for(int i=0;i<n;i++){
		if(m==0) m=1;
		if(r==0) r=1;
		m=m*arr[i];

		r=r*arr[n-i-1];
		maxi=max(maxi,max(m,r));
	}
	return maxi;
    }
};