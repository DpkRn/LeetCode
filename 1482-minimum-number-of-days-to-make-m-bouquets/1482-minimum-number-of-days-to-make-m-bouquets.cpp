class Solution
{
    int canWeMake(vector<int> &bloomDay, int day, int k, int m)
    {
        int n = bloomDay.size();
        int noOfB = 0, noOfF = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
                noOfF++;
            else
            {
                noOfB += noOfF / k;
                noOfF = 0;
            }
        }
        noOfB += noOfF / k;
        return noOfB >= m;
    }
    public:
        int minDays(vector<int> &bloomDay, int m, int k)
        {
            int n = bloomDay.size();
            int maxi = 0, mini = 1e9 + 1;
            for (int i = 0; i < n; i++)
            {
                maxi = max(maxi, bloomDay[i]);
                mini = min(mini, bloomDay[i]);
            }

            int low = mini, high = maxi;
            if (m *1ll * k > n) return -1;
            while (low <= high)
            {
                int mid = (low + high) >> 1;
                if (canWeMake(bloomDay, mid, k, m))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }
};