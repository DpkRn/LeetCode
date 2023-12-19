class Solution
{
    int isValidDiv(vector<int> &nums, int threshold, int num)
    {
        int divisons = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            divisons += ceil((double) nums[i] / num);
            if (divisons > threshold) return 0;
        }
        return 1;
    }
    public:
        int smallestDivisor(vector<int> &nums, int threshold)
        {
            int low = 1;
            int high = *max_element(nums.begin(), nums.end());
            while (low <= high)
            {
                int mid = (low + high) >> 1;
                if (isValidDiv(nums, threshold, mid))
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return low;
        }
};