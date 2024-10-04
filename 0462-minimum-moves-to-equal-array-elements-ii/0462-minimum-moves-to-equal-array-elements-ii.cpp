class Solution {
public:
//nums[i] <= centre <= nums[n-1-i]
//nums[i]) + (nums[n-1-i] - x) = nums[n-1-i] - nums[i] where x is element after taking some movies
    int minMoves2(vector<int>& nums) {
         int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            steps += nums[n-1-i] - nums[i]; //Adding difference
        }
        return steps;
    }
};

/*
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2]; // Finding median
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median); //Adding absolute difference
        }
        return steps;
    }
};

*/