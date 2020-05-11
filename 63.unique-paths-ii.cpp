/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int dp[101][101];
    int row,col;
    int f(const vector<vector<int>> &x ,int m, int n)
    {
        if(x[row-m][col-n] == 1){
            return 0;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        if (m == 1 && n == 1)
        {
            return 1;
        }
        int ans1 = (m > 1) ? f(x,m - 1, n) : 0;
        int ans2 = (n > 1) ? f(x,m, n - 1) : 0;
        dp[m][n] = ans1 + ans2;
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        row = obstacleGrid.size();
        if(row==0){
            return 0;
        }
        col = obstacleGrid[0].size();
        if(col==0){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return f(obstacleGrid,row, col);        
    }
};
// @lc code=end

