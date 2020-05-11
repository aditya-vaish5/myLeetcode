/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int row = matrix.size();
        if(row ==0){
            return ans;
        }
        int col = matrix[0].size();
        if(col==0) return ans;
        int count = 0;
        for (int i = 0; count < row * col; i++)
        {
            for (int j = i; j < col - i; j++)
            {
                count++;
                ans.push_back(matrix[i][j]);
            }
            if (count >= row * col)
            {
                break;
            }
            for (int j = i + 1; j < row - 1 - i; j++)
            {
                count++;
                ans.push_back(matrix[j][col - i - 1]);
            }
            if (count >= row * col)
            {
                break;
            }
            for (int j = col - i - 1; j >= i; j--)
            {
                count++;
                ans.push_back(matrix[row - i - 1][j]);
            }
            if (count >= row * col)
            {
                break;
            }
            for (int j = row - 2 - i; j > i; j--)
            {
                count++;
                ans.push_back(matrix[j][i]);
            }
            if (count >= row * col)
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
