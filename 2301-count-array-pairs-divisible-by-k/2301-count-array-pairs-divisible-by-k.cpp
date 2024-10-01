class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
         unordered_map<int,int> factorCount;
        long long result =0;
        int previousIndexCount = 0; // stores any Index that was traversed before
        for (int i=0;i<nums.size(); i++){
            int factor = gcd(nums[i], k); // this is the "useful" part of nums[i]
            int missingFactor = k/factor; // what other factor is needed to form k
            
            if (missingFactor==1){ // if missingFactor is 1, the that means nums[i] can match with any previous index to form a pair, k*n %k == 0
                result += previousIndexCount;
            }else{ // if m is not 1, we can check if any previous index has the missing factor
                for (auto it=factorCount.begin(); it!=factorCount.end(); it++){
                    if ( it->first % missingFactor == 0){
                        result += it->second;
                    }
                }
            }
            // only add the "useful" factor part to the map
            factorCount[factor]++;
            previousIndexCount++;
            
        }
        return result;
    }
};