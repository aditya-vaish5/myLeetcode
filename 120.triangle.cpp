/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int n;
    int dp[1000][1000];
    int f(vector<vector<int>> &triangle, int curr, int last)
    {
        if(dp[curr][last] != -1)
            return dp[curr][last];
        if (curr == n)
            return 0;
        dp[curr][last] =min(triangle[curr][last] + f(triangle, curr + 1, last),
                   triangle[curr][last + 1] + f(triangle, curr + 1, last + 1));
        return dp[curr][last];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        memset(dp,-1,sizeof(dp));
        n = triangle.size();
        return triangle[0][0] + f(triangle, 1, 0);
    }
};
// @lc code=end
