class Solution {
  public:
    int strangePrinter(::std::string s) {
        s.erase(::std::unique(s.begin(), s.end()), s.end());
        size_t n = s.size();
        ::std::vector<::std::vector<int>> dp(n, ::std::vector<int>(n));
        for (size_t i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (size_t k = 1; k < n; ++k) {
            for (size_t i = 0; i < n - k; ++i) {
                size_t j = i + k;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = ::std::numeric_limits<int>::max();
                    for (size_t l = i; l < j; ++l) {
                        dp[i][j] = ::std::min(dp[i][j], dp[i][l] + dp[l + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};