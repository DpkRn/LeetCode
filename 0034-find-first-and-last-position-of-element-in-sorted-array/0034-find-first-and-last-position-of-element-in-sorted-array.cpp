class Solution {
public:
int upperBound(vector<int> &arr, int n, int x){
	int low=0;int high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else
		low=mid+1;
	}
	return ans;	
}

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int l=0;int h=n-1;
	int ans=n;
	while(l<=h){
		int m=(l+h)/2;
		if(arr[m]>=x){
			ans=m;
			h=m-1;
		}else l=m+1;
	}
	return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOcc=lowerBound(nums,nums.size(),target);
        int lastOcc=upperBound(nums,nums.size(),target);
        if(firstOcc==lastOcc) return {-1,-1};
        return {firstOcc,lastOcc-1};
    }
};


/*
class Solution {
 public:
    pair<int,int> ans;
   auto it=lower_bound(arr.begin(),arr.end(),k);
    auto itu=upper_bound(arr.begin(),arr.end(),k);
    if(it!=itu){
        ans.first=it-arr.begin();
        ans.second=itu-arr.begin()-1;
    }
   return ans;
}
*/