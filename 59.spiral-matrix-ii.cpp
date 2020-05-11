/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n , vector<int> (n,0));
        if (n == 0)
        {
            return ans;
        }
        int count = 0;
        int n2 = n * n;
        for (int i = 0; count < n2; i++)
        {
            if (count == n2)
                break;
            for (int j = i; j < n - i; j++)
            {
                count++;
                ans[i][j] = count;
            }
            if (count == n2)
                break;
            for (int j = i + 1; j < n - i - 1; j++)
            {
                count++;
                ans[j][n - i - 1] = count;
            }
            if (count == n2)
                break;
            for (int j = n - i - 1; j >= i; j--)
            {
                count++;
                ans[n - i - 1][j] = count;
            }
            if (count == n2)
                break;
            for (int j = n - i - 2; j >= i + 1; j--)
            {
                count++ ;
                ans[j][i]= count;
            }
        }
        return ans;

    }
};
// @lc code=end
