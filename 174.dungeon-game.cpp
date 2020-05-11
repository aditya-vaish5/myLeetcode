/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution
{
public:
    int m, n;
    // first is lower_bound , second is curr value
    int dp[1001][1001];
    int f(const vector<vector<int>> &mat, int i, int j)
    {
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int atleast;
        if(i == m-1 && j == n-1){
            atleast = 1-mat[i][j];
        }else if(i == m-1) {
            atleast = f(mat,i ,j+1) - mat[i][j];
        }else if(j == n-1) {
            atleast = f(mat, i+1,j) - mat[i][j];
        }else{
            atleast = (min(f(mat, i + 1, j), f(mat, i, j + 1))) - mat[i][j];
        }
        dp[i][j] = atleast <= 0 ? 1 : atleast;
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1,sizeof(dp));
        return f(dungeon, 0, 0);
    }
};
// @lc code=end
