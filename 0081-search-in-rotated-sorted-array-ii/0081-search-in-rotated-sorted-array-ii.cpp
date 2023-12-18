class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
     int l=0;int h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]==k) return 1;
        if(arr[l]==arr[m]&&arr[m]==arr[h]){
            l++;h--; continue;
        }
        if(arr[l]<=arr[m]){ //checking left array is sorted then?
            if(arr[l]<=k&&k<arr[m]) //then search in left 
                h=m-1; //if yes then eleminate right array
            else
                l=m+1; //other wise eliminate the left array 
        }
        else{ //if right array is sorted then
             if(arr[h]>=k&&arr[m]<k) //then search target in right array 
                l=m+1; //if found eliminate left
             else 
                h=m-1; //if not found eliminate right
        }
    }
    return 0;
    }
};