/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows == 0)
            return ans;
        vector<int> t;
        t.push_back(1);
        ans.push_back(t);

        for (int i = 2; i <= numRows; i++)
        {
            vector<int> x;
            cout << i << endl;
            x.assign( i,0);
            for (int j = 0; j < i - 1; j++)
            {
                x[j] += ans[i - 2][j];
                x[j + 1] += ans[i - 2][j];
            }
            for (auto p : x)
            {
                cout << p << ' ';
            }
            cout << endl;
            ans.push_back(x);
        }
        return ans;
    }
};
// @lc code=end
