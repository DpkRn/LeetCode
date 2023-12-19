class Solution
{
    int canShipInGivenDay(vector<int> &weights, int days, int weightOfship)
    {
        int totalDay = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] <= weightOfship)
            {
                sum += weights[i];
            }
            else
            {
                totalDay++;
                sum = weights[i];
            }
            if (totalDay > days) return 0;
        }
        return 1;
    }
    public:
        int shipWithinDays(vector<int> &weights, int days)
        {
            int maxi = INT_MIN;
            int n = weights.size();
            int totalSum = 0;
            for (int i = 0; i < n; i++)
            {
                totalSum += weights[i];
                maxi = max(maxi, weights[i]);
            }

            int low = maxi;
            int high = totalSum;
            while (low <= high)
            {
                int mid = (low + high) >> 1;
                if (canShipInGivenDay(weights, days, mid))
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