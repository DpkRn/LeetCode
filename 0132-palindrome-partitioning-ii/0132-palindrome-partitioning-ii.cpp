class Solution
{
    public:
        bool isPalindrome ( int i, int j,string & s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int f(int i, string &s, auto &dp)
    {
         if(i>=s.size() or isPalindrome(i,s.size(),s)) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cnt = 1 + f(j + 1, s, dp);
                mini = min(mini, cnt);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
        // vector<int> dp(n + 1, 0);
        // for (int i = n-1; i >= 0; i--)
        // {
        //     int mini = INT_MAX;
        //     for (int j = i; j < s.size(); j++)
        //     {
        //         if (isPal(i, j, s))
        //         {
        //             int cnt = 1 + dp[j + 1];
        //             mini = min(mini, cnt);
        //         }
        //         dp[i] = mini;
        //     }
        // }
        // return dp[0]-1;
    }
};