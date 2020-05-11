/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int dp[101][101];
    int f(int m, int n)
    {
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        if (m == 1 && n == 1)
        {
            return 1;
        }
        int ans1 = m > 1 ? f(m - 1, n) : 0;
        int ans2 = n > 1 ? f(m, n - 1) : 0;
        dp[m][n] = ans1 + ans2;
        return dp[m][n];
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return f(m, n);
    }
};
// @lc code=end
