class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &a, vector<int> &b)
        {
            int n1 = a.size();
            int n2 = b.size();
            int l = 0, r = 0;
            int n = (n1 + n2);
            int ind2 = n / 2;
            int ind1 = ind2 - 1;
            int ind1el = -1;
            int ind2el = -1;
            int cnt = 0;
            int flag = false;
            while (l < n1 && r < n2 && flag == false)
            {
                if (a[l] < b[r])
                {
                    if (cnt == ind1) ind1el = a[l];
                    if (cnt == ind2)
                    {
                        ind2el = a[l];
                        flag = true;
                    }
                    cnt++;
                    l++;
                }
                else
                {
                    if (cnt == ind1) ind1el = b[r];
                    if (cnt == ind2)
                    {
                        ind2el = b[r];
                        flag = true;
                    }
                    cnt++;
                    r++;
                }
            }
            while (l < n1 && flag == false)
            {
                if (cnt == ind1) ind1el = a[l];
                if (cnt == ind2)
                {
                    ind2el = a[l];
                    flag = true;
                }
                cnt++;
                l++;
            }
            while (r < n2 && flag == false)
            {
                if (cnt == ind1) ind1el = b[r];
                if (cnt == ind2)
                {
                    ind2el = b[r];
                    flag == true;
                }
                cnt++;
                r++;
            }

            if (n % 2 == 1)
                return (double)(ind2el);

            return (double)(ind1el + ind2el) / 2.0;
        }
};